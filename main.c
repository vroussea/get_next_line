/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 17:39:40 by vroussea          #+#    #+#             */
/*   Updated: 2016/02/16 12:55:41 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		fd1;
	int		fd2;
	int		result;
	int		result1;
	int		result2;
	char	*line;

	if (argc >= 2 && argc <= 4)
	{
		fd = open(argv[1], O_RDONLY);
		fd1 = open(argv[2], O_RDONLY);
		fd2 = open(argv[3], O_RDONLY);
		result = 1;
		result1 = 1;
		result2 = 1;
		while (result == 1 || result1 == 1 || result2 == 1)
		{
			if (result > 0)
				result = get_next_line(fd, &line);
			if (result >= 0)
			{
				ft_putendl(argv[1]);
				ft_putstr("return : ");
				ft_putendl(ft_itoa(result));
				ft_putstr("line : ");
				ft_putendl(line);
				ft_strdel(&line);
				if (result == 0)
					result--;
			}
			if (result1 > 0)
				result1 = get_next_line(fd1, &line);
			if (result1 >= 0)
			{
				ft_putendl(argv[2]);
				ft_putstr("line : ");
				ft_putendl(line);
				ft_strdel(&line);
				if (result1 == 0)
					result1--;
			}
			if (result2 > 0)
				result2 = get_next_line(fd2, &line);
			if (result2 >= 0)
			{
				ft_putendl(argv[3]);
				ft_putstr("line : ");
				ft_putendl(line);
				ft_putendl("");
				ft_strdel(&line);
				if (result2 == 0)
					result2--;
			}
		}
		close(fd);
		close(fd1);
		close(fd2);
		ft_putstr("Entrer phrase pour verifier ce qu'il y a dans line : ");
		get_next_line(0, &line);
		ft_putendl(line);
	}
	else
		ft_putendl("error");
	return (0);
}
