/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 22:34:52 by tdumouli          #+#    #+#             */
/*   Updated: 2017/07/13 00:05:12 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_treeiter(t_leaf *lst, void (*f)(t_leaf *elem))
{
	if (lst)
	{
		ft_treeiter(lst->gauche, f);
		ft_treeiter(lst->droite, f);
		f(lst);
	}
}
