/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bracket.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 17:09:52 by tdumouli          #+#    #+#             */
/*   Updated: 2017/07/19 17:18:29 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

char		*bracket(char *av, char test, char *t1, char *t2)
{
	int		t_len;
	int		i;

	if (!(t_len = ft_strlen(t1)) || t_len != (int)ft_strlen(t2))
		return (NULL);
	while (*av)
	{
		i = 0;
		if (*av == test)
			return (av);
		while (*(t1 + i) && *(t1 + i) != *av)
			++i;
		if (i != t_len && !(av = bracket(av + 1, *(t2 + i), t1, t2)))
			return (NULL);
		else if (i == t_len)
		{
			i = 0;
			while (*(t2 + i) && *(t2 + i) != *av)
				++i;
			if (i != t_len)
				return (NULL);
		}
		++av;
	}
	return (test ? NULL : av);
}
