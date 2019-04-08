/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 23:25:32 by tdumouli          #+#    #+#             */
/*   Updated: 2016/12/26 17:17:29 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(const t_list *where, void *whi)
{
	t_list	*are_you;

	are_you = (t_list *)where;
	while (are_you && ft_strcmp(are_you->content, whi))
		are_you = are_you->next;
	return (are_you);
}
