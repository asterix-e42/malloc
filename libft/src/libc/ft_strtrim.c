/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 21:48:44 by tdumouli          #+#    #+#             */
/*   Updated: 2017/08/24 16:26:06 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		sup_deb;
	int		sup_fin;
	int		ln;
	char	*ret;

	if (!s)
		return (NULL);
	sup_deb = 0;
	ln = -1;
	sup_fin = 0;
	while (*(++ln + s) && ft_isspace(*(ln + s)))
		sup_deb++;
	while (*(++ln + s))
		if (ft_isspace(*(ln + s)))
			sup_fin++;
		else
			sup_fin = 0;
	if (!(ret = (char *)malloc(sizeof(char) * ((ln -= sup_deb + sup_fin) + 1))))
		return (NULL);
	if (-sup_deb == ln)
		return (ret);
	*(ret + ln) = '\0';
	while (ln-- > 0)
		*(ret + ln) = *(s + sup_deb + ln);
	return (ret);
}
