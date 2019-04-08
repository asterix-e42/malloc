/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 21:52:25 by tdumouli          #+#    #+#             */
/*   Updated: 2017/10/04 22:04:13 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>

char	*ft_strnjoin(int nbr, ...)
{
	int		i;
	va_list	args;
	char	*ret;
	char	*tmp;

	i = 0;
	va_start(args, nbr);
	ret = ft_memalloc(sizeof(char));
	while (i < nbr)
	{
		tmp = ret;
		free(tmp);
		if (!(tmp = va_arg(args, char *)))
		{
			ft_putendl_fd("Error: nbr too big", 2);
			exit(0);
		}
		ret = ft_strjoin(ret, tmp);
		i++;
	}
	va_end(args);
	return (ret);
}
