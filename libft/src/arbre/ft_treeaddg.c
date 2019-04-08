/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeaddg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 21:05:00 by tdumouli          #+#    #+#             */
/*   Updated: 2017/07/19 17:17:13 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_treeaddg(t_leaf *alst, t_leaf *new)
{
	if (!new)
		return (1);
	new->gauche = alst->gauche;
	alst->gauche = new;
	new->prev = alst;
	return (0);
}
