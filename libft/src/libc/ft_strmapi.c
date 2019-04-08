/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 20:06:54 by tdumouli          #+#    #+#             */
/*   Updated: 2016/11/11 12:31:08 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = ft_strlen(s);
	if (!(ret = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	*(i + ret) = '\0';
	while (i-- > 0)
		*(ret + i) = f(i, *(s + i));
	return (ret);
}
