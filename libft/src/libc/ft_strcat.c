/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 02:56:30 by tdumouli          #+#    #+#             */
/*   Updated: 2017/08/31 23:14:06 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char		*ft_strcat(char *restrict dest, const char *restrict src)
{
	int		i;
	int		end_dest;
	int		length;

	length = ft_strlen(src);
	end_dest = ft_strlen(dest);
	i = -1;
	while (i++ < length)
		*(dest + i + end_dest) = *(src + i);
	return (dest);
}
