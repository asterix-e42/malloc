/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:14:11 by tdumouli          #+#    #+#             */
/*   Updated: 2016/12/15 05:48:34 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "libft.h"
#include <math.h>

int		ft_atoibase(char *nb, char *b1)
{
	char	*ret;
	int		tmp;
	size_t	size;
	int		skt;
	int		max;

	if (!b1)
		return (0);
	tmp = -1;
	skt = 0;
	max = ft_strlen(nb) - 1;
	size = ft_strlen(b1);
	while (*(nb + ++tmp))
	{
		ret = b1 - 1;
		while (*(++ret) != *(nb + tmp))
			if (!*(ret))
				return (0);
		skt += (int)(ret - b1) * pow(size, max - tmp);
	}
	return (skt);
}
