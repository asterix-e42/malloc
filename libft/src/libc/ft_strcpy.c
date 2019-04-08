/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 03:01:37 by tdumouli          #+#    #+#             */
/*   Updated: 2017/09/01 00:01:33 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;
	int	lenght;

	lenght = ft_strlen(src);
	i = -1;
	if (dest < src)
		while (i++ < lenght)
			*(dest + i) = *(src + i);
	else
		while (lenght--)
			*(dest + lenght) = *(src + lenght);
	return (dest);
}
