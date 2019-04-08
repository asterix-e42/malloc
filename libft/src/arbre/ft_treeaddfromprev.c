/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeaddfromprev.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 16:47:16 by tdumouli          #+#    #+#             */
/*   Updated: 2017/07/15 16:56:53 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_treeaddfromprev(t_leaf *before, t_leaf *after)
{
	if (!before->prev)
		return (2);
	if (before->prev->droite == before)
		before->prev->droite = after;
	else if (before->prev->gauche == before)
		before->prev->gauche = after;
	else
	{
		write(2, "addprev : perte de lien\n", 24);
		return (0);
	}
	return (1);
}
