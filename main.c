/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:53:47 by kbagot            #+#    #+#             */
/*   Updated: 2016/12/16 16:48:33 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char	*line;
	char	*line2;
	char	*line3;
	int		fd;
	int		fd2;
	int		fd3;
	int		lol;

	lol = 100;
	if (argc)
	{
		line3 = NULL;
		line2 = NULL;
		line = NULL;
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		fd3 = open(argv[3], O_RDONLY);
		while (lol-- > 1)
		{
			if (get_next_line(fd, &line))
				printf("[FD1]%s\n", line);
			if (get_next_line(fd2, &line2))
				printf("[FD2]%s\n", line2);
			if (get_next_line(fd3, &line3))
				printf("[FD3]%s\n", line3);
		}
	}
	return (0);
}
