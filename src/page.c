/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 22:44:21 by tdumouli          #+#    #+#             */
/*   Updated: 2019/05/26 22:44:22 by tdumouli         ###   ########.fr       */
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

void		create_page(int size_page, int size)
{
	g_mem->next->where = 0;
	if (size_page != 2)
	{
		g_mem->next->index = alloc(1);
		ft_bzero(g_mem->next->index, getpagesize());
		g_mem->next->data = alloc((size_page ? 16 : 1) * TINY_MAX);
	}
	else
	{
		g_mem->next->where = size;
		g_mem->next->data = alloc(size);
	}
	g_mem->next->next = g_mem->pages[size_page];
	g_mem->pages[size_page] = g_mem->next;
	++g_mem->next;
}

static int	search(void *addr, int *blk, int size_page)
{
	t_page	*page_cur;
	int		x;

	page_cur = g_mem->pages[size_page];
	blk[2] = 0;
	while (page_cur && (addr < page_cur->data || addr >= page_cur->data +
				(size_page ? 16 : 1) * getpagesize() * TINY_MAX))
	{
		page_cur = page_cur->next;
		++blk[2];
	}
	if (!page_cur)
		return (6);
	x = addr - page_cur->data;
	x /= (size_page ? 16 : 1);
	blk[0] = x / 256;
	blk[1] = (x % 256) / 16;
	if (*(short int *)(page_cur->index + blk[0] + BLOCK_START) & 1 << blk[1])
		return (size_page);
	return (5);
}

int			search_block(void *addr, int *blk)
{
	int		size_page;
	t_page	*page_cur;
	int		x;

	size_page = -1;
	if (!addr || (long long int)addr % (16))
		return (5);
	while (++size_page != 2)
		if ((x = search(addr, blk, size_page)) != 6)
			return (x);
	page_cur = g_mem->pages[size_page];
	blk[2] = 0;
	while (page_cur)
	{
		if (page_cur->data == addr)
			return (2);
		++blk[2];
		page_cur = page_cur->next;
	}
	return (5);
}
