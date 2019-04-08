/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 06:21:14 by tdumouli          #+#    #+#             */
/*   Updated: 2017/09/03 23:22:08 by tdumouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		remplissage(const int fd, char **line, int i, char **buf)
{
	char	*tmp;
	int		rd;
	int		flag;

	while (*(*line + i) != '\n' && *(*line + i) != -1 && (*((*line) + i)))
		++i;
	flag = (*(*line + i) == '\n' || *(*line + i) == -1);
	while (!flag && (rd = read(fd, *buf, BUFF_SIZE)))
	{
		if (rd == -1)
			return (-1);
		(*buf)[rd] = '\0';
		i = 0;
		while (*(*buf + i) != '\n' && i != rd)
			++i;
		if (!(*(*buf + i) == '\n') || !(flag = 1))
			*(*buf + i + 1) = '\0';
		if (!(tmp = ft_strjoin(*line, *buf)))
			return (-1);
		free(*line);
		*line = tmp;
	}
	return (flag);
}

int		decoupage(char **line, char **stk)
{
	int		deb;
	int		end;
	char	*tmp;

	deb = 0;
	end = 0;
	while (*(*line + deb) != '\n' && *(*line + deb) && *(*line + deb) != -1)
		++deb;
	while (*(*line + deb + end) != -1 && *(*line + deb + end) != '\0')
		++end;
	tmp = *line;
	*stk = ft_strsub(tmp, 0, deb);
	*line = ft_strsub(tmp, deb + 1, end - 1);
	free(tmp);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char			*buf;
	static t_list	*lsd;
	t_list			*offset;
	int				ret;

	if (!(offset = (ft_lstfindsize(lsd, fd))))
	{
		if (!(offset = ft_lstnew("\0", 1)))
			return (-1);
		offset->content_size = fd;
		ft_lstadd(&lsd, offset);
	}
	if (!(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	if ((ret = remplissage(fd, (char **)&(offset->content), 0, &buf)) == -1)
		return (-1);
	free(buf);
	if (!ret && !*(char *)offset->content)
		return (0);
	decoupage((char **)&(offset->content), line);
	return (1);
}
