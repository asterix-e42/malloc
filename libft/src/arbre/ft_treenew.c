/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:03:31 by tdumouli          #+#    #+#             */
/*   Updated: 2017/07/11 21:06:01 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

t_leaf	*ft_treenew(void const *conten, size_t content_siz)
{
	t_leaf	*ret;
	char	*s;

	if (!(ret = (t_leaf *)malloc(sizeof(t_leaf))))
		return (NULL);
	ret->prev = NULL;
	ret->gauche = NULL;
	ret->droite = NULL;
	if (!conten)
	{
		ret->content = NULL;
		ret->content_size = 0;
		return (ret);
	}
	if (!(ret->content = malloc(content_siz)))
		return (NULL);
	ret->content_size = content_siz;
	s = (char *)ret->content;
	while (content_siz--)
		*(s + content_siz) = *(char *)(conten + content_siz);
	return (ret);
}
