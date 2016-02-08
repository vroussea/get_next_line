/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 17:39:40 by vroussea          #+#    #+#             */
/*   Updated: 2016/02/02 21:07:09 by vroussea         ###   ########.fr       */
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
		ft_putendl("Fichier vide ? (1 oui, 0 non)");
		get_next_line(0, &line);
		if (*line == '1')
		{
			ft_putendl("Ecrire 5 phrases : ");
			fd = open(argv[1], O_WRONLY);
			result = 0;
			while (result < 5)
			{
				result++;
				ft_putstr("phrase ");
				ft_putnbr(result);
				ft_putstr(" : ");
				get_next_line(0, &line);
				ft_putendl_fd(line, fd);
			}
			close(fd);
		}
		fd = open(argv[1], O_RDONLY);
		result = 1;
		while (result == 1)
		{
			result = get_next_line(fd, &line);
			if (result >= 0)
			{
				ft_putstr("line : ");
				ft_putendl(line);
			}
		}
		if (result == -1)
			ft_putendl("error");
		close(fd);
		ft_strdel(&line);
		ft_putstr("Entrer phrase pour verifier ce qu'il y a dans line : ");
		get_next_line(0, &line);
		ft_putendl(line);
	}
	else
		ft_putendl("error");
	return (0);
}
