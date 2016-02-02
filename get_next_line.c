/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 22:07:54 by vroussea          #+#    #+#             */
/*   Updated: 2016/02/02 23:49:29 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

static t_file	*new_node(int const fd)
{
	t_file	*new;

	ft_putendl("mdr");
	new = (t_file *)ft_memalloc(sizeof(t_file));
	ft_putendl("mdr2");
	new->fd = fd;
	new->str = ft_strnew(BUFF_SIZE);
	ft_putendl("mdr3");
	new->next = NULL;
	return (new);
}

static t_file	*test_node(int const fd, t_file *start)
{
	t_file	*current;
	t_file	*tmp;

	current = start;
	tmp = start;
	while (current)
	{
		if (current->fd == fd)
		{
			return (current);
		}
		tmp = current;
		current = current->next;
	}
	current = new_node(fd);
	tmp->next = current;
	return (current);
}

int				get_next_line(int const fd, char **line)
{
	static t_file	*start;
	t_file			*crt;
	char			*buff;
	int				ret;

	start = new_node(0);
	if (BUFF_SIZE <= 0 || !(buff = (char *)ft_memalloc(BUFF_SIZE)))
		return (-1);
	ret = 1;
	crt = test_node(fd, start);
	while (!ft_strchr(crt->str, '\n') && ret > 0)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		if (ret > 0)
			ft_strcat(crt->str, buff);
	}
	*line = (!ft_strchr(crt->str, '\n') ? ft_strsub(crt->str, 0, ft_strlen(crt->str)) :
			ft_strsub(crt->str, 0, ft_strchr(crt->str, '\n') - crt->str));
	if (ret != 0)
		crt->str = ft_strsub(crt->str, ft_strchr(crt->str, '\n') - crt->str + 1,
			ft_strlen(crt->str) - (ft_strchr(crt->str, '\n') - crt->str));
	ft_strdel(&buff);
	return (ret ? 1 : 0);
}
