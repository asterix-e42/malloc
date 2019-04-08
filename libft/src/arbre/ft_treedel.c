/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treedel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:33:03 by tdumouli          #+#    #+#             */
/*   Updated: 2017/07/11 20:33:06 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_treedel(t_leaf **alst, void (*del)(void *, size_t))
{
	if (*alst)
	{
		ft_treedel(&((*alst)->gauche), del);
		ft_treedel(&((*alst)->droite), del);
		ft_treedelone(alst, del);
	}
}
