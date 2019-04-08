/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 02:54:53 by tdumouli          #+#    #+#             */
/*   Updated: 2019/04/06 23:25:23 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned int	i;

	d = dest;
	i = -1;
	if (dest < src)
		while (++i < n)
			*(d + i) = *((unsigned char *)src + i);
	else if (dest > src)
		while (++i < n)
			*(d + n - i - 1) = *((unsigned char *)src + n - i - 1);
	return (dest);
}
