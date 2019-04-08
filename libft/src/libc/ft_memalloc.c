/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:51:34 by tdumouli          #+#    #+#             */
/*   Updated: 2016/11/09 00:16:22 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (size--)
		*(ret + size) = 0;
	return (ret);
}
