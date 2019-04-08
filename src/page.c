
#include "malloc.h"
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <string.h>

void create_page(int size_page, int size)
{	
	if(g_mem->pages[size_page])
		g_mem->next->next = g_mem->pages[size_page];
	g_mem->pages[size_page] = g_mem->next;

	if(size_page != 2)
	{
		g_mem->pages[size_page]->index = alloc(1);
		bzero(g_mem->pages[size_page]->index, getpagesize());
		g_mem->pages[size_page]->data = alloc(SIZE(size_page) * TINY_MAX);
	}
	else
	{
		g_mem->pages[size_page]->index = NULL + size; //ou where
		g_mem->pages[size_page]->data = alloc(size);
	}
	g_mem->pages[size_page]->where = 0;
	//bzero(g_mem->pages[i]->data, getpagesize());
	//cree blk
	g_mem->next = (void *)((long long int)g_mem->next + sizeof(t_page));
}

int search_block(void *addr, int *blk)
{
	int size_page;
	void *tmp;
	t_page *page_cur;
	int x;



//	ft_putendl("    search");
	//printf("\naddr %p\n", addr);


	size_page = -1;
	tmp = NULL;

	if(!addr || (long long int)addr % (16))
	{
//		ft_putendl("non aligner");
		return (5);
	}

	while(++size_page != 2)
	{
		page_cur = g_mem->pages[size_page];
		////printf("size_pagei %p\n", page_cur->data);
		////printf("size_pagei %p\n", page_cur->data + (SIZE(size_page) * getpagesize() * TINY_MAX));
		blk[2] = 0;
		while(page_cur && (addr < page_cur->data || addr >= page_cur->data + SIZE(size_page) * getpagesize() * TINY_MAX))
		{
			page_cur = page_cur->next;
			++blk[2];
		}
		if(!page_cur)
		{
			continue;
		}

		x = addr - page_cur->data;
		x = x / SIZE(size_page);
		blk[0] = x / 256;
		blk[1] = (x % 256) / 16;

		////printf("o %s\n", strbin(*(int *)(page_cur->index + 0), 32));
		////printf("o %s\n", strbin(*(int *)(page_cur->index + 4), 32));
		if(*(short int *)(page_cur->index + blk[0] + BLOCK_START) & 1 << blk[1])
		{
			//printf("\ntrouver!!!!!!!!!!!%d\n\n", size_page);
			return(size_page);
		}
		//printf("pas trouver\n");
		return(5);	
	}
	page_cur = g_mem->pages[size_page];
	blk[2] = 0;
	while(page_cur)
	{
		//printf("%d c'est gros\n", size_page);
		if (page_cur->data == addr)
			return (2);
		++blk[2];
		//printf("%d c'est gros2\n", size_page);
		page_cur = page_cur->next;
	}
	//printf("nop nop nop pas bon endroi\n");
	return (5);
}
