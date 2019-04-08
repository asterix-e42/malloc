/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 02:54:53 by tdumouli          #+#    #+#             */
/*   Updated: 2019/04/06 23:24:50 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*d;
	unsigned int	i;

	d = dest;
	i = -1;
	while (++i < n)
		*(d + i) = *(char *)(src + i);
	return (dest);
}
