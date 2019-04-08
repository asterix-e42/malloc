/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:59:00 by tdumouli          #+#    #+#             */
/*   Updated: 2017/09/19 21:42:02 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char *tab;

	if (!(tab = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	size++;
	while (size--)
		*(tab + size) = '\0';
	return (tab);
}
