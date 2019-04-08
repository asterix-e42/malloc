/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 02:58:04 by tdumouli          #+#    #+#             */
/*   Updated: 2016/11/08 23:34:47 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int					ft_memcmp(const void *s1, const void *s2, size_t size)
{
	int				ret;
	unsigned int	i;

	ret = 0;
	i = -1;
	while (++i < size && !ret)
		ret = *(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i);
	return (ret);
}
