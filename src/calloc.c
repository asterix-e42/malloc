#include "malloc.h"
#include "libft.h"
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <string.h>

void	*calloc(size_t nmemb, size_t size)
{
	void	*ret;

	ret = malloc(size * nmemb);
	pthread_mutex_lock(&g_mutex);
	ft_bzero(ret, size * nmemb);
	pthread_mutex_unlock(&g_mutex);
	return (ret);
}
