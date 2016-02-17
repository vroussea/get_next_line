/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:34:37 by vroussea          #+#    #+#             */
/*   Updated: 2016/02/17 16:26:18 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		fd;
	char	*line;
	int		result;

	if (argc == 2)
	{
		fd = open(argv[1], O_WRONLY);
		i = 0;
		result = 1;
		while (result)
		{
			i++;
			ft_putstr("phrase ");
			ft_putnbr(i);
			ft_putstr(" : ");
			result = get_next_line(0, &line);
			ft_putstr("line : ");
			j = 0;
			while (line[j] != '\0')
			{
				ft_putnbr(line[j]);
				ft_putchar(' ');
				j++;
			}
			ft_putstr("result : ");
			ft_putendl(ft_itoa(result));
			ft_putendl_fd(line, fd);
		}
		close(fd);
	}
}
