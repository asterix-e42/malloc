/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 22:55:51 by tdumouli          #+#    #+#             */
/*   Updated: 2017/09/20 23:05:25 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		test2;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	len = 0;
	i = -1;
	while (*(s + ++i))
		len += (*(s + i) != c) && (i == 0 || (*(s + i - 1) == c));
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * (len + 1))))
		return (NULL);
	*(tab + len) = NULL;
	while (len-- > 0)
	{
		test2 = 0;
		while (*(s + i) == c || !*(s + i))
			i--;
		while ((i >= test2) && (*(s + i - test2) != c || !test2))
			test2++;
		i -= test2;
		tab[len] = ft_strsub(s, i + 1, test2);
	}
	return (tab);
}
