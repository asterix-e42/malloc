/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstothernew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 02:28:56 by tdumouli          #+#    #+#             */
/*   Updated: 2017/04/11 20:22:35 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

t_list	*ft_lstothernew(size_t fd)
{
	t_list	*ret;

	if (!(ret = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	ret->next = NULL;
	if (!(ret->content = malloc(1)))
		return (NULL);
	ret->content_size = fd;
	return (ret);
}
