
#ifndef MALLOC_H

#include <stddef.h>
# include <pthread.h>
# define MALLOC_H
# define TINY 256 - 16
# define SMALL 4096 - 256
# define LARGE 0x0

# define TINY_MAX 8
# define SMALL_MAX 128
# define BLOCK_START 128

# define SIZE(x) (x ? 16 : 1)
# define MAX(a, b) ((a) > (b) ? (a) : (b))
# define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct		s_page
{
	void			*index;
	void			*data;
	struct s_page	*next;
	int				where;
	int				s;
}					t_page;

typedef struct		s_mem
{
	t_page			*pages[3];
	t_page			*next;
	void			*begin;
}					t_mem;

t_mem				*g_mem;
static pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;


void *malloc(size_t size);
int search_block(void *addr, int *blk);
void create_page(int i, int size);
void *alloc(size_t size);
int define_size(size_t *size);
void show_alloc_mem();
void clean_free(t_page *page, int *blk);
void remplissage(int size, int i, int *blk);
t_page *goto_page(int i, int blk);
void strbin(const unsigned int n, const short nbBits);

#endif
