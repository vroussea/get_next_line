/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 17:39:40 by vroussea          #+#    #+#             */
/*   Updated: 2016/01/27 18:04:13 by vroussea         ###   ########.fr       */
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
			get_next_line(fd, line);
		}
		if (result == -1)
			ft_putendl("error");
		close(fd);
	}
	return (0);
}
