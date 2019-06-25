/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 22:43:57 by tdumouli          #+#    #+#             */
/*   Updated: 2019/06/25 17:38:45 by tdumouli         ###   ########.fr       */
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

pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;

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

void			*ft_malloc(size_t size)
{
	int			blk[3];
	int			size_bloc;
	void		*ret;

	size_bloc = define_size(&size);
	if (!g_mem->pages[size_bloc] || size_bloc == 2)
		create_page(size_bloc, (int)size);
	if (size_bloc == 2)
		return (add_next_return(g_mem->pages[size_bloc]->data));
	remplissage(size, size_bloc, blk);
	ret = goto_page(size_bloc, blk[2]);
	size_bloc = (size_bloc ? 16 : 1);
	ret = ((t_page *)ret)->data + (blk[0] * 16 + blk[1]) * 16 * size_bloc;
	return (add_next_return(ret));
}

void			*malloc(size_t size)
{
	if (!g_mem)
	{
		if ((g_mem = alloc(1)) <= 0)
			return (NULL);
		ft_bzero(g_mem, getpagesize());
		g_mem->begin = g_mem;
		g_mem->next = (void *)((long long int)g_mem + sizeof(t_mem));
	}
	pthread_mutex_lock(&g_mutex);
	return (ft_malloc(size));
}
