/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 22:44:10 by tdumouli          #+#    #+#             */
/*   Updated: 2019/06/26 16:41:45 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <string.h>

void	*calloc(size_t nmemb, size_t size)
{
	void	*ret;

	ret = malloc(size * nmemb);
	ft_bzero(ret, size * nmemb);
	return (ret);
}
