#include "malloc.h"
#include "libft.h"
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <string.h>

void	clean_free(t_page *page, int *blk)
{
	while (!(*(short int *)(page->index + blk[0] + BLOCK_START) & 1 << blk[1]))
	{
		if (!(*(short int *)(page->index + blk[0]) & 1 << blk[1]))
			break ;
		*(short int *)(page->index + blk[0]) -= 1 << blk[1];
		++blk[1];
	}
}

void	clean_large(void *addr)
{
	t_page	*tmp;
	t_page	*page;

	page = g_mem->pages[2];
	tmp = NULL;
	while (page->data != addr)
	{
		tmp = page;
		page = tmp->next;
	}
	if (!tmp)
		g_mem->pages[2] = page->next;
	else
		tmp->next = page->next;
}

void	ft_free(void *addr)
{
	int		blk[3];
	int		size_page;
	t_page	*page;

	size_page = search_block(addr, blk);
	if (size_page == 5)
	{
		return ;
	}
	if (size_page == 2)
	{
		clean_large(addr);
		return ;
	}
	page = goto_page(size_page, blk[2]);
	if (!(*(short int *)(page->index + blk[0] + BLOCK_START) & 1 << blk[1]))
	{
		return ;
	}
	*(short int *)(page->index + blk[0] + BLOCK_START) -= 1 << blk[1];
	clean_free(page, blk);
}

void	free(void *addr)
{
	pthread_mutex_lock(&g_mutex);
	ft_free(addr);
	pthread_mutex_unlock(&g_mutex);
}
