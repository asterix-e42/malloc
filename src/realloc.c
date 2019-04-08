
#include "malloc.h"
#include "libft.h"
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <string.h>


void *change_page(void *ptr, size_t size, int *size_page, int size_block)
{
	void *ret;

	ret = malloc(size);
	size_page[1] = define_size(&size);
	if (size_page[1] < size_page[0])
		memcpy(ret, ptr, size * SIZE(size_page[1]) * 16);
	else if (size_page[1] > size_page[0])
		memcpy(ret, ptr, size_block * SIZE(size_page[0]) * 16);
	else
		memcpy(ret, ptr, MIN(size_block, (int)size) * getpagesize());
	free(ptr);
	return(ret);
}

void *meme_page(void *ptr, int size, int *size_page, int size_block)
{
	void *ret;

	free(ptr);
	ret = malloc(size);
	memcpy(ret, ptr, size_block * SIZE(MIN(size_page[1], size_page[0])) * 16);
	return(ret);
}

void	*realloc(void *ptr, size_t size)
{
	int blk[3];
	int size_page[2];
	t_page *page;
	size_t size_tmp;
	int size_block;

	size_tmp = size;
	if (!ptr)
		return(malloc(size));
	if((size_page[0] = search_block(ptr, blk)) == 5)
		return(NULL);

	size_page[1] = define_size(&size);
	
	page = goto_page(size_page[0], blk[2]);

	if (size_page[0] == 2)
	{

		//printf("chop %d = %d, %d = 2\n", (int)page->index, (int)size, size_page[1]);
		if((int)page->index ==  (int)size &&  size_page[1] == 2)
			return(ptr);
		return(change_page(ptr, size_tmp, size_page, (int)page->index));
	}

	if (!(*(short int *)(page->index + blk[0] + BLOCK_START) & 1 << blk[1]))
		exit(1);

	size_block = 0;
	////printf("i %s\n", strbin((*(short int *)(page->index + blk[0] + BLOCK_START)), 32));
	while(!(*(short int *)(page->index + blk[0] + BLOCK_START) & 1 << (blk[1] + ++size_block)))
	{
		if (!(*(short int *)(page->index + blk[0]) & 1 << (blk[1] + size_block)))
			break;
		//++size_block;
	}
	if (size_page[1] == size_page[0])
	{
		if ((int)size < size_block)
		{
			blk[1] += size;
			clean_free(page, blk);
		}
		else if ((int)size > size_block)
		{
			return(meme_page(ptr, size_tmp, size_page, size_block));
		}
		return(ptr);
	}	
	return(change_page(ptr, size_tmp, size_page, size_block));
}
