/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 02:58:29 by tdumouli          #+#    #+#             */
/*   Updated: 2016/11/13 21:10:35 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*dest_pt;
	const unsigned char	*src_pt;

	dest_pt = dest;
	src_pt = src;
	while (n-- > 0)
	{
		if ((*dest_pt++ = *src_pt++) == (unsigned char)c)
			return ((void *)dest_pt);
	}
	return (NULL);
}
