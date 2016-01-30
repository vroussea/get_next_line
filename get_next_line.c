/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 22:07:54 by vroussea          #+#    #+#             */
/*   Updated: 2016/01/30 19:35:55 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int const fd, char **line)
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
		ft_putstr("ret : ");
		ft_putendl(ft_itoa(ret));
		ft_putendl(buff);
		if (ret == -1)
			return (-1);
		if (ret > 0)
			ft_strncat(str, buff, ft_strchr(buff, '\n') - buff + 1);
	}
	i = 0;
	ft_putendl("str existe");
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putendl("str existe");
	*line = (!ft_strchr(str, '\n') ? ft_strsub(str, 0, ft_strlen(str)) :
			ft_strsub(str, 0, ft_strchr(str, '\n') - str));
	ft_putendl("test");
	return (ret ? 1 : 0);
}
