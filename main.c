/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 17:39:40 by vroussea          #+#    #+#             */
/*   Updated: 2016/02/01 22:05:30 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		result;
	char	*line;

	if (argc == 2)
	{
		result = 1;
		fd = open(argv[1], O_RDONLY);
		while (result == 1)
		{
			result = get_next_line(fd, &line);
			ft_putstr("ret : ");
			ft_putendl(ft_itoa(result));
			ft_putstr("line : ");
			ft_putendl(line);
		}
		if (result == -1)
			ft_putendl("error");
		close(fd);
	}
	else
		ft_putendl("error");
	return (0);
}
