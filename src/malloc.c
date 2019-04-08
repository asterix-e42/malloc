
#include "malloc.h"
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <string.h>


int define_size(size_t *size)
{
	int i;

	i = 0;
	*size = (*size - 1) / 16 + 1;
	while (*size > 15 && i != 2)
	{
		++i;
		*size = (*size - 1) / 16 + 1;
	}
	return (i);
}

void *alloc(size_t size)
{
	char *ret;

	ret = mmap(NULL, size * getpagesize(), PROT_READ | PROT_WRITE, MAP_ANON | MAP_SHARED, -1, 0);
	//printf("addr %s\n", ret);
	////printf("size %d\n", size);
	return(ret);
}

void remplissage(int size, int i, int *blk)
{
	short int	fill_blk;
	int			tmp;
	t_page		*page;

	page = g_mem->pages[i];
	fill_blk = 0;
	tmp = size;
	while(tmp--)
		fill_blk = (fill_blk << 1) + 1;
	//short int fill_blk_2 = -1;
	//fill_blk_2 >>= size;
	//fill_blk_2 = !fill_blk_2;
	//printf("size %d\n", size);
	////printf("fill_blk %s\n", strbin(fill_blk, 64));
	////printf("fill_blk %s\n", strbin(fill_blk_2, 64));


	blk[0] = 0;
	blk[1] = 0;
	blk[2] = 0;
	while(blk[1] != 16)
	{
//		int tmp_1 = *(int *)(g_mem->pages[i]->index + blk[0]) | (fill_blk << blk[1]); 
//		int tmp_2 = *(int *)(g_mem->pages[i]->index + blk[0]) + (fill_blk << blk[1]); 
//		//printf(" 1  %s\n", strbin(fill_blk << blk[1], 64));
//		//printf(" 2  %s  \n", strbin(*(int *)(g_mem->pages[i]->index + blk[0]), 64));
//		//printf("tmp %s\n", strbin(tmp_1, 64));
//		//printf("nop %s\n", strbin(tmp_2, 64));
		  
		if((*(int *)(page->index + blk[0]) | (fill_blk << blk[1])) == 
				(*(int *)(page->index + blk[0]) + (fill_blk << blk[1])))
		{
			*(int *)(page->index + blk[0]) |= (fill_blk << blk[1]);
			break;
		}
		else if(blk[1] == 16 - size)
		{
			blk[1] = -1;
			blk[0] += 2;	
		}
		if (blk[0] == BLOCK_START)
		{
			//printf("ko\n");
			blk[0] = 0;
			blk[1] = -1;
			if(!page->next)
			{
				create_page(i, size);
				page = g_mem->pages[i];
			}
			else
			{
				page = page->next;
				++blk[2];
			}
		}
		++blk[1];
	}

//	//printf(" 2   %d\n", blk[0]);
//	//printf(" 2   %d\n", blk[1]);
//	//printf(" 2  %p\n", (int *)(page->index + blk[0] * 16 + blk[1] + BLOCK_START));
//	//printf(" 2  %p\n", (int *)(page->index));

	*(short int *)(page->index + blk[0] + BLOCK_START) |= 1 << blk[1];
	g_mem->pages[i]->where = MAX(g_mem->pages[i]->where, blk[0]);
}

t_page *goto_page(int i, int blk)
{
	t_page *ret;
	ret = g_mem->pages[i];
	while(blk--)
		ret = ret->next;
	return (ret);
}

void *malloc(size_t size)
{
	int		blk[3];
	int		i;
	void	*ret;

	//ft_putnbr((int)size);
	//ft_putendl("  size");
	if(!g_mem)
	{
		g_mem = alloc(1);
		ft_bzero(g_mem, getpagesize());
		g_mem->next = (void *)((long long int)g_mem + sizeof(t_mem));

			//printf("g_mem %p  - %p\n", g_mem , &(g_mem));
//			//printf("g_mem %lu  - %p\n", sizeof(t_mem) , &(g_mem->next));
//		//printf("g_mem %p  - %p\n", g_mem->next , g_mem);

	}
	i = define_size(&size);
	
	if(!g_mem->pages[i] || i == 2)
		create_page(i, (int)size);

//	//printf("g_mem %p  - %p\n", g_mem->next , g_mem);
	//*(int *)(g_mem->pages[i]->index) = 7; 
	
	////printf("malloc %p\n", g_mem->pages[i]->data);
	if(i == 2)
		return(g_mem->pages[i]->data);
	remplissage(size, i, blk);


	ret = goto_page(i, blk[2]);
	ret = ((t_page *)ret)->data + blk[0] * 256 * SIZE(i) + blk[1] * 16 * SIZE(i);
	////printf("malloc %p\n", g_mem->pages[i]->data);
	////printf("malloc %p\n", ret);
	////printf("%s\n", strbin(*(int *)(g_mem->pages[i]->index + 0), 32));
	////printf("%s\n", strbin(*(int *)(g_mem->pages[i]->index + 4), 32));

//	//printf("%s\n", strbin(*(int *)(g_mem->pages[i]->index + 0), 32));
//	//printf("%s\n", strbin(*(int *)(g_mem->pages[i]->index + 4), 32));
	return (ret);
}
