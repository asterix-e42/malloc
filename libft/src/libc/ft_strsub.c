/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 21:09:06 by tdumouli          #+#    #+#             */
/*   Updated: 2017/07/18 03:38:57 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret;

	if (!s)
		return (NULL);
	i = start;
	while (*(s + i) && i < start + len)
		i++;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1 + !(len)))))
		return (NULL);
	if (i != start + len || !(len))
	{
		*ret = '\0';
		return (ret);
	}
	i = 0;
	*(ret + len) = '\0';
	while (i++ < len)
		*(ret + i - 1) = *(s + i + start - 1);
	return (ret);
}
