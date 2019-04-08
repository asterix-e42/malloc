/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 23:32:07 by tdumouli          #+#    #+#             */
/*   Updated: 2017/09/28 04:06:23 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_stralloc(char **src, char *ajout)
{
	char	*tmp;

	tmp = *src;
	if (!ajout)
		return (1);
	if (!(*src = (char *)ft_memalloc(sizeof(char) *
					(ft_strlen(*src) + ft_strlen(ajout) + 1))))
		return (2);
	ft_strcpy(*src, tmp);
	ft_strcat(*src, ajout);
	free(tmp);
	return (0);
}
