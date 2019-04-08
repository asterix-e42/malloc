
#ifndef MALLOC_H

#include <stddef.h>
#include "libft.h"
# define MALLOC_H
# define TINY 256 - 16
# define SMALL 4096 - 256
# define LARGE 0x0

# define TINY_MAX 8
# define SMALL_MAX 128
# define BLOCK_START 512

# define SIZE(x) (x ? 16 : 1)
# define SIZE_TYPE(x) (x ? "SMALL" : "TINY")
# define MAX(a, b) ((a) > (b) ? (a) : (b))
# define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct		s_page
{
	void			*index;
	void			*data;
	struct s_page	*next;
	char			where;
}					t_page;

typedef struct		s_mem
{
	t_page			*pages[3];
	t_page			*next;
}					t_mem;

/*typedef struct		s_mem
{
	void			*pages[3];
}					t_mem;
*/
t_mem				*g_mem;



void *malloc(size_t size);
int search_block(void *addr, int *blk);
void create_page(int i, int size);
void *alloc(size_t size);
int define_size(size_t *size);
void show_alloc_mem();
void clean_free(t_page *page, int *blk);
void remplissage(int size, int i, int *blk);
t_page *goto_page(int i, int blk);
char    *strbin(const unsigned int n, const short nbBits);

#endif
