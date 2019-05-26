/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 22:43:57 by tdumouli          #+#    #+#             */
/*   Updated: 2019/05/26 22:46:51 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <string.h>

static void		change_page(int size, int iii, int *blk, t_page **page)
{
	blk[0] = 0;
	blk[1] = -1;
	if (!(*page = (*page)->next))
	{
		create_page(iii, size);
		*page = g_mem->pages[iii];
		blk[2] = 0;
	}
	else if (((*page)->index))
		++blk[2];
	else
		change_page(size, iii, blk, page);
}

void			remplissage(int size, int iii, int *blk)
{
	short int	fill_blk;
	int			tmp;
	t_page		*page;

	page = g_mem->pages[iii];
	fill_blk = 0;
	tmp = size;
	while (tmp--)
		fill_blk = (fill_blk << 1) + 1;
	blk[0] = 0;
	blk[1] = -1;
	blk[2] = 0;
	while (++blk[1] != 16)
	{
		if ((*(int *)(page->index + blk[0]) | (fill_blk << blk[1])) ==
				(*(int *)(page->index + blk[0]) + (fill_blk << blk[1])))
			break ;
		else if ((blk[1] == 16 - size) && (blk[1] = -1))
			blk[0] += 2;
		if (blk[0] >= BLOCK_START)
			change_page(size, iii, blk, &page);
	}
	*(int *)(page->index + blk[0]) |= (fill_blk << blk[1]);
	*(short int *)(page->index + blk[0] + BLOCK_START) |= 1 << blk[1];
	g_mem->pages[iii]->where = max(g_mem->pages[iii]->where, blk[0]);
}

t_page			*goto_page(int i, int blk)
{
	t_page		*ret;

	ret = g_mem->pages[i];
	while (blk--)
		ret = ret->next;
	return (ret);
}

void			*add_next_return(void *ret)
{
	if ((void *)g_mem->next >
		((void *)(g_mem->begin + getpagesize() - sizeof(t_page))))
	{
		if ((g_mem->begin = alloc(1)) <= 0)
			ret = NULL;
		else
			g_mem->next = g_mem->begin;
	}
	pthread_mutex_unlock(&g_mutex);
	return (ret);
}

void			*malloc(size_t size)
{
	int			blk[3];
	int			i;
	void		*ret;

	if (!g_mem)
	{
		if ((g_mem = alloc(1)) <= 0)
			return (NULL);
		ft_bzero(g_mem, getpagesize());
		g_mem->begin = g_mem;
		g_mem->next = (void *)((long long int)g_mem + sizeof(t_mem));
	}
	pthread_mutex_lock(&g_mutex);
	i = define_size(&size);
	if (!g_mem->pages[i] || i == 2)
		create_page(i, (int)size);
	if (i == 2)
		return (add_next_return(g_mem->pages[i]->data));
	remplissage(size, i, blk);
	ret = goto_page(i, blk[2]);
	i = (i ? 16 : 1);
	ret = ((t_page *)ret)->data + blk[0] * 256 * i + blk[1] * 16 * i;
	return (add_next_return(ret));
}
