/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:44:34 by tdumouli          #+#    #+#             */
/*   Updated: 2017/08/31 23:13:35 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t s)
{
	size_t		end_dest;
	size_t		length;

	length = ft_strlen(src);
	end_dest = ft_strlen(dst);
	if (s <= end_dest)
		return (length + s);
	if (s > end_dest + length)
		s = end_dest + length + 1;
	*(dst + --s) = '\0';
	while (s-- != end_dest)
		*(dst + s) = *(src + s - end_dest);
	return (length + end_dest);
}
