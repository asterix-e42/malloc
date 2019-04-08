/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treedelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 20:27:52 by tdumouli          #+#    #+#             */
/*   Updated: 2017/07/11 20:30:05 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	ft_treedelone(t_leaf **alst, void (*del)(void*, size_t))
{
	if (*alst)
	{
		if (!((*alst)->droite) && !((*alst)->gauche))
		{
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = NULL;
		}
		else
			write(1, "seulement les derniere branche/n", 31);
	}
}
