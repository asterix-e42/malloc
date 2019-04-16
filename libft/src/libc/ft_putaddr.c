/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 01:22:51 by tdumouli          #+#    #+#             */
/*   Updated: 2019/04/16 03:06:19 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_putaddr(void *nb, char *b2)
{
	char					s[256];
	unsigned long int		tmp;
	size_t					size;
	int						skt;
	unsigned int			max;

	if (!b2 && !*b2 && !*(b2 + 1))
		exit(1);
	ft_putstr("0x");
	tmp = (long long)nb;
	skt = 0;
	max = ft_strlen(b2);
	size = 1;
	while (tmp /= max)
		++size;
	tmp = (long long)nb;
	*(s + size) = '\0';
	while (--size + 1)
	{
		*(s + size) = *(b2 + (tmp % max));
		tmp /= max;
	}
	ft_putstr(s);
}
