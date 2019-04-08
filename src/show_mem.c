
#include "malloc.h"
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <string.h>

void print_alloc_mem_large(void *addr1, int addr2, long long int *total)
{
	printf("%p - ", addr1);
	printf("%p : ", addr1 + addr2);
	*total += addr2;
	printf("%d octets\n", addr2);

}

void print_alloc_mem(void *addr1, void *addr2, long long int *total)
{
	printf("%p - ", addr1);
	printf("%p : ", addr2);
	*total += addr2 - addr1;
	printf("%ld octets\n", addr2 - addr1);

}

void show_alloc_mem()
{
	long long int total;
	int size_page;
	int		blk[3];
	void *tmp;
	t_page *page_cur;

	total = 0;
	size_page = -1;
	blk[0] = 0;
	blk[1] = 0;
	tmp = NULL;

	while(++size_page != 2)
	{
	page_cur = g_mem->pages[size_page];
	while(page_cur)
	{
		blk[0] = 0;
		blk[1] = 0;
		printf("%s : %p\n",SIZE_TYPE(size_page), page_cur->data);
		while(blk[0] <= page_cur->where)
		{
			if(*(short int *)(page_cur->index + blk[0] + BLOCK_START) & 1 << blk[1])
			{
		//		//printf("1 %d\n", blk[0]);
		//		//printf("2 %d\n", page_cur->where);
				if (tmp)
					print_alloc_mem(tmp, (((t_page *)page_cur)->data + blk[0] * 256 * SIZE(size_page) + blk[1] * 16 * SIZE(size_page)), &total);
				tmp = ((t_page *)page_cur)->data + blk[0] * 256 * SIZE(size_page) + blk[1] * 16 * SIZE(size_page);

				//chop size
			}
			else if(tmp && !(*(short int *)(page_cur->index + blk[0]) & (1 << blk[1])))
			{
				print_alloc_mem(tmp, ((t_page *)page_cur)->data + blk[0] * 256 * SIZE(size_page) + blk[1] * 16 * SIZE(size_page), &total);
				tmp = NULL;
			}
			if(++blk[1] == 16)
			{
				blk[0] += 2;
				blk[1] = 0;
			}
		}
		if (tmp)
		{
			print_alloc_mem(tmp, (((t_page *)page_cur)->data + blk[0] * 256 * SIZE(size_page) + blk[1] * 16 * SIZE(size_page)), &total);
			tmp = NULL;
		}
		page_cur = page_cur->next;
	}
	}
	page_cur = g_mem->pages[size_page];
	if (page_cur)
		printf("LARGE : %p\n", page_cur->data);
	while(page_cur)
	{
		print_alloc_mem_large(page_cur->data, (int)page_cur->index * getpagesize(), &total);
		page_cur = page_cur->next;
	}
	printf("Total : %lld octets\n", total);
}	
