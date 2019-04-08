/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 04:16:56 by tdumouli          #+#    #+#             */
/*   Updated: 2017/03/18 18:44:23 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *s)
{
	int		parcourt;
	int		is_neg;
	int		ret;

	parcourt = -1;
	is_neg = 1;
	ret = 0;
	while (ft_isspace(*(++parcourt + s)))
		;
	if (*(parcourt + s) == '-' || *(parcourt + s) == '+')
	{
		if (*(parcourt + s) == '-')
			is_neg = -1;
	}
	else
		parcourt--;
	while ('0' <= *(++parcourt + s) && *(parcourt + s) <= '9')
		ret = ret * 10 + (*(parcourt + s) - '0') * is_neg;
	return (ret);
}
