/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfindsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 00:43:13 by tdumouli          #+#    #+#             */
/*   Updated: 2016/12/26 17:16:56 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfindsize(const t_list *where, int whi)
{
	t_list	*are_you;

	if (!where)
		return (NULL);
	are_you = (t_list *)where;
	while (are_you && (int)are_you->content_size != whi)
		are_you = are_you->next;
	return (are_you);
}
