/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 22:44:27 by tdumouli          #+#    #+#             */
/*   Updated: 2019/05/26 22:44:28 by tdumouli         ###   ########.fr       */
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

void	print_alloc_mem(void *addr1, void *addr2, long long int *total, int siz)
{
	ft_putaddr(addr1, "0123456789ABCDEF");
	ft_putstr(" - ");
	if (siz == 2)
		ft_putaddr((int)addr2 * getpagesize() + addr1, "0123456789ABCDEF");
	else
		ft_putaddr(addr2, "0123456789ABCDEF");
	ft_putstr(" : ");
	if (siz == 2)
		ft_putnbr(getpagesize() * (int)addr2);
	else
		ft_putnbr(addr2 - addr1);
	ft_putendl(" octets");
	if (siz == 2)
		*total += (int)addr2 * getpagesize();
	else
		*total += addr2 - addr1;
}

void	print_begin(int size_page, t_page *page_cur)
{
	if (!page_cur)
		return ;
	if (!size_page)
		ft_putstr("TINY");
	else if (size_page == 1)
		ft_putstr("SMALL");
	else
		ft_putstr("lARGE");
	ft_putstr(" : ");
	ft_putaddr(page_cur->data, "0123456789ABCDEF");
	ft_putendl("");
}

void	aff_small(t_page *page_cur, long long *total, int *blk, void **tmp)
{
	if (*(short int *)(page_cur->index + blk[0] + BLOCK_START) & 1 << blk[1])
	{
		if (*tmp)
			print_alloc_mem(*tmp, (((t_page *)page_cur)->data + blk[0] * 256 *
						blk[2] + blk[1] * 16 * blk[2]), total, blk[2]);
		*tmp = ((t_page *)page_cur)->data + blk[0] * 256 *
			blk[2] + blk[1] * 16 * blk[2];
	}
	else if (*tmp && !(*(char *)(page_cur->index + blk[0]) & (1 << blk[1])))
	{
		print_alloc_mem(*tmp, ((t_page *)page_cur)->data + blk[0] * 256 *
				blk[2] + blk[1] * 16 * blk[2], total, blk[2]);
		*tmp = NULL;
	}
	if (++blk[1] == 16)
	{
		blk[0] += 2;
		blk[1] = 0;
	}
}

void	aff_small_tiny(t_page *page_cur, int size_page, long long *total)
{
	void			*tmp;
	int				blk[3];

	blk[2] = (size_page ? 16 : 1);
	while (page_cur)
	{
		blk[0] = 0;
		blk[1] = 0;
		print_begin(size_page, page_cur);
		while (blk[0] <= page_cur->where)
		{
			aff_small(page_cur, total, blk, &tmp);
		}
		if (tmp)
		{
			print_alloc_mem(tmp, (((t_page *)page_cur)->data + blk[0] * 256
						* blk[2] + blk[1] * 16 * blk[2]), total, blk[2]);
		}
		page_cur = page_cur->next;
	}
}

void	show_alloc_mem(void)
{
	long long int	total;
	int				size_page;
	t_page			*page_cur;

	pthread_mutex_lock(&g_mutex);
	total = 0;
	size_page = -1;
	while (++size_page != 2)
	{
		aff_small_tiny(g_mem->pages[size_page], size_page, &total);
	}
	page_cur = g_mem->pages[size_page];
	print_begin(size_page, page_cur);
	while (page_cur)
	{
		print_alloc_mem(page_cur->data, page_cur->index, &total, size_page);
		page_cur = page_cur->next;
	}
	ft_putstr("Total : ");
	ft_putnbr(total);
	ft_putendl(" octets");
	pthread_mutex_unlock(&g_mutex);
}
