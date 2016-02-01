/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 22:07:54 by vroussea          #+#    #+#             */
/*   Updated: 2016/02/01 23:10:45 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>


int			get_next_line(int const fd, char **line)
{
	static char	str[BUFF_SIZE];
	char		*buff;
	int			ret;
	int			i;

	if (BUFF_SIZE <= 0 || !(buff = (char *)ft_memalloc(BUFF_SIZE)))
		return (-1);
	ret = 1;
	while (!ft_strchr(str, '\n') && ret > 0)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		if (ret > 0)
			ft_strncat(str, buff, ft_strlen(buff));
	}
	*line = (!ft_strchr(str, '\n') ? ft_strsub(str, 0, ft_strlen(str)) :
			ft_strsub(str, 0, ft_strchr(str, '\n') - str));
	if (ret != 0)
	{
		buff = ft_strsub(str, ft_strchr(str, '\n') - str + 1,
			ft_strlen(str) - (ft_strchr(str, '\n') - str));
		i = 0;
		while (buff[i])
		{
			str[i] = buff[i];
			i++;
		}
		str[i] = '\0';
	}
	ft_strdel(&buff);
	return (ret ? 1 : 0);
}
