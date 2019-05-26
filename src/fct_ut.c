/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_ut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 22:43:34 by tdumouli          #+#    #+#             */
/*   Updated: 2019/05/26 22:45:43 by tdumouli         ###   ########.fr       */
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

int				define_size(size_t *size)
{
	int			i;

	i = 0;
	*size = (*size - 1) / 16 + 1;
	while (*size > 15 && i != 2)
	{
		++i;
		*size = (*size - 1) / 16 + 1;
	}
	return (i);
}

void			*alloc(size_t size)
{
	char		*ret;

	ret = mmap(NULL, size * getpagesize(),
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_SHARED, -1, 0);
	return (ret);
}

void			strbin(const unsigned int n, const short nb_bits)
{
	unsigned	bit;
	unsigned	mask;
	char		buffer[256];
	int			i;

	bit = 0;
	mask = 1;
	i = -1;
	while (++i < nb_bits)
	{
		bit = (n & mask) >> i;
		buffer[nb_bits - 1 - i] = (char)('0' + bit);
		mask <<= 1;
	}
	buffer[nb_bits] = '\0';
	ft_putendl(buffer);
}
