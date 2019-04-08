/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 22:40:59 by tdumouli          #+#    #+#             */
/*   Updated: 2017/01/05 20:00:24 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*deb;

	if (!lst || !f)
		return (NULL);
	ret = f(lst);
	deb = ret;
	while (lst->next)
	{
		lst = lst->next;
		if (!(ret->next = f(lst)))
		{
			free(deb);
			return (NULL);
		}
		ret = ret->next;
	}
	return (deb);
}
