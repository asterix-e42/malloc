/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 04:46:44 by tdumouli          #+#    #+#             */
/*   Updated: 2017/09/01 02:17:21 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

t_list	*ft_lstnew(void const *conten, size_t content_siz)
{
	t_list	*ret;
	char	*s;

	if (!(ret = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	ret->next = NULL;
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
