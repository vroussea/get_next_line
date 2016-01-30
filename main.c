/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 17:39:40 by vroussea          #+#    #+#             */
/*   Updated: 2016/01/30 17:08:12 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		result;
	char	**line;

	if (argc == 2)
	{
		line = NULL;
		result = 1;
		fd = open(argv[1], O_RDONLY);
		while (result == 1)
		{
			result = get_next_line(fd, line);
			ft_putendl("test");
			ft_putendl(*line);
		}
		if (result == -1)
			ft_putendl("error");
		close(fd);
	}
	return (0);
}
