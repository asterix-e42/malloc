/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 19:37:26 by tdumouli          #+#    #+#             */
/*   Updated: 2016/11/11 12:30:42 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	int		i;

	if (!s || !f)
		return (NULL);
	i = ft_strlen(s);
	if (!(ret = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	*(i + ret) = '\0';
	while (i-- > 0)
		*(ret + i) = f(*(s + i));
	return (ret);
}
