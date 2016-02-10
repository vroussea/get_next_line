/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 22:07:54 by vroussea          #+#    #+#             */
/*   Updated: 2016/02/10 19:11:53 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

static void		cleaner(t_file *crt, int ret, char **line)
{
	t_file	*tmp;
	char	*tmpstring;

	if (crt->str)
		*line = (!ft_strchr(crt->str, '\n') ?
				ft_strsub(crt->str, 0, ft_strlen(crt->str)) :
				ft_strsub(crt->str, 0, ft_strchr(crt->str, '\n') - crt->str));
	if (ret != 0)
	{
		tmpstring = ft_strsub(crt->str,
				ft_strchr(crt->str, '\n') - crt->str + 1, ft_strlen(crt->str) -
				(ft_strchr(crt->str, '\n') - crt->str));
		ft_strdel(&(crt->str));
		crt->str = tmpstring;
	}
	if (ret == 0 && crt && crt->prev)
	{
		tmp = crt->prev;
		tmp->next = crt->next;
		ft_strdel(&crt->str);
		ft_memdel((void **)&crt);
		crt = NULL;
	}
}

static t_file	*new_node(int const fd)
{
	t_file	*new;

	new = (t_file *)ft_memalloc(sizeof(t_file));
	new->fd = fd;
	new->str = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	new->prev = NULL;
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
	if (current->fd != start->fd)
		current->prev = tmp;
	return (current);
}

static int		reader(int ret, t_file *crt, int fd)
{
	char	*buff;
	char	*tmp;

	if (BUFF_SIZE <= 0 || !(buff = (char *)ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	while (!ft_strchr(crt->str, '\n') && ret > 0)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		if (ret > 0)
		{
			tmp = crt->str;
			crt->str = ft_strjoin(crt->str, buff);
			ft_strdel(&tmp);
		}
	}
	ft_strdel(&buff);
	return (ret);
}

int				get_next_line(int const fd, char **line)
{
	static t_file	*start = NULL;
	t_file			*crt;
	int				ret;

	if (start == NULL)
		start = new_node(0);
	ret = 1;
	crt = test_node(fd, start);
	if ((ret = reader(ret, crt, fd)) == -1)
		return (-1);
	cleaner(crt, ret, line);
	return ((ret && (ft_strlen(crt->str) > 0)) ? 1 : 0);
}
