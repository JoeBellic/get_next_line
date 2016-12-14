/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:53:47 by kbagot            #+#    #+#             */
/*   Updated: 2016/12/14 19:09:23 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
//	int		fd2;
	int		lol;

	lol = 8;
	if (argc)
	{
		line = NULL;
		fd = open(argv[1], O_RDONLY);
//		fd2 = open(argv[2], O_RDONLY);
		while (lol-- > 1)
		{
			if (get_next_line(fd, &line))
				printf("lignefd1 : %s|||||\n", line);
//			if (get_next_line(fd2, &line))
//				printf("lignefd2 : %s|||||\n", line);
		}
	}
	return (0);
}
