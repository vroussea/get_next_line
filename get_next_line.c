/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 22:07:54 by vroussea          #+#    #+#             */
/*   Updated: 2016/01/27 21:35:02 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int const fd, char **line)
{
	static char	*buff;
	int			ret;

	if (BUFF_SIZE <= 0)
		return (-1);
	if (!(buf = (char *)ft_memalloc(BUFF_SIZE)))
		return (-1);
	while (!ft_strchr(buff, '\n') && ret != -1)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == -1)
			return (-1);
	}
	*line = (!ft_strchr(buff, '\n') ? ft_strsub(): );
	return (ret ? 1 : 0);
}
