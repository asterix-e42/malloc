/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 03:08:28 by tdumouli          #+#    #+#             */
/*   Updated: 2017/02/28 20:39:17 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char		*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = -1;
	while (*(src + ++i) && i < n)
		*(dest + i) = *(src + i);
	while (i++ < n)
		*(dest + i - 1) = '\0';
	return (dest);
}
