/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeaddd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 21:07:38 by tdumouli          #+#    #+#             */
/*   Updated: 2017/07/19 17:17:07 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_treeaddd(t_leaf *alst, t_leaf *new)
{
	if (!new)
		return (1);
	new->gauche = alst->droite;
	alst->droite = new;
	new->prev = alst;
	return (0);
}
