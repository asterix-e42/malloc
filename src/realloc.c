#include "malloc.h"
#include "libft.h"
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <string.h>

static void	*change_page(void *ptr, size_t size, int *size_page, int size_block)
{
	void	*ret;

	ret = malloc(size);
	size_page[1] = define_size(&size);
	if (size_page[1] < size_page[0])
		memcpy(ret, ptr, size * SIZE(size_page[1]) * 16);
	else if (size_page[1] > size_page[0])
		memcpy(ret, ptr, size_block * SIZE(size_page[0]) * 16);
	else
		memcpy(ret, ptr, MIN(size_block, (int)size) * getpagesize());
	free(ptr);
	return (ret);
}

static void	*same(size_t size_tmp, int *size_block, int *blk, void *ptr)
{
	size_t	siize;
	int		size_page;
	t_page	*page;
	void	*ret;

	siize = size_tmp;
	size_page = define_size(&siize);
	page = goto_page(size_page, blk[2]);
	while (!(*(short *)(page->index + blk[0] + BLOCK_START) &
				1 << (blk[1] + ++*size_block)))
		if (!(*(short *)(page->index + blk[0]) & 1 << (blk[1] + *size_block)))
			break ;
	if ((int)siize < *size_block)
	{
		blk[1] += siize;
		clean_free(page, blk);
	}
	else if ((int)siize > *size_block)
	{
		free(ptr);
		ret = malloc(size_tmp);
		memcpy(ret, ptr, *size_block * SIZE(size_page) * 16);
		return (ret);
	}
	return (ptr);
}

static void	*ft_realloc(void *ptr, size_t siize)
{
	int		blk[3];
	int		size_page[2];
	t_page	*page;
	size_t	size_tmp;
	int		size_block;

	size_tmp = siize;
	size_block = 0;
	if ((size_page[0] = search_block(ptr, blk)) == 5)
		return (NULL);
	size_page[1] = define_size(&siize);
	page = goto_page(size_page[0], blk[2]);
	if (size_page[0] == 2)
	{
		if ((int)page->index == (int)siize && size_page[1] == 2)
			return (ptr);
		return (change_page(ptr, size_tmp, size_page, (int)page->index));
	}
	if (!(*(short int *)(page->index + blk[0] + BLOCK_START) & 1 << blk[1]))
		return (NULL);
	if (size_page[1] == size_page[0])
		return (same(size_tmp, &size_block, blk, ptr));
	return (change_page(ptr, size_tmp, size_page, size_block));
}

void		*realloc(void *ptr, size_t siize)
{
	void	*ret;

	if (!ptr)
		return (malloc(siize));
	pthread_mutex_lock(&g_mutex);
	ret = ft_realloc(ptr, siize);
	pthread_mutex_unlock(&g_mutex);
	return (ret);
}
