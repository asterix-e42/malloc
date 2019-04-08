/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 19:36:21 by tdumouli          #+#    #+#             */
/*   Updated: 2017/08/23 19:42:07 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strndup(const char *src, int nb)
{
	char	*dup;
	int		i;

	if (!(dup = (char*)malloc((nb + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (src[i] && i < nb)
	{
		dup[i] = src[i];
		i++;
	}
	while (i <= nb)
	{
		dup[i] = '\0';
		i++;
	}
	return (dup);
}
