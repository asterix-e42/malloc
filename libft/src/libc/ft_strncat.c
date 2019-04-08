/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 03:07:50 by tdumouli          #+#    #+#             */
/*   Updated: 2017/03/02 19:17:22 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char		*ft_strncat(char *restrict dest, const char *restrict src, size_t n)
{
	size_t		i;
	size_t		end_dest;
	size_t		length;

	length = ft_strlen(src);
	end_dest = ft_strlen(dest);
	i = -1;
	while (++i < length && i < n)
		*(dest + i + end_dest) = *(src + i);
	*(dest + i + end_dest) = '\0';
	return (dest);
}
