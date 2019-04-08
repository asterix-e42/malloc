/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 02:59:38 by tdumouli          #+#    #+#             */
/*   Updated: 2017/02/28 20:40:07 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memset(void *src, int val, size_t size)
{
	char			*s;
	unsigned int	i;

	s = src;
	i = -1;
	while (++i < size)
	{
		*(s + i) = val;
	}
	return (src);
}
