/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:37:51 by kbagot            #+#    #+#             */
/*   Updated: 2016/12/08 20:20:44 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	**ft_make_line(char **line, char **rstr, int i, int buff_size)
{
	int	j;
	int n;
	int l;

	l = 0;
	n = 0;
	j = 0;
	line = (char**)malloc(sizeof(char*) * 2);
	line[0] = (char*)malloc(sizeof(char) * i + 1);
	while (rstr[j])
	{
		ft_strcpy(&line[0][l], rstr[j]);
		i = i - buff_size;
		l = l + buff_size;
		j++;
	}
	line[0][l] = '\0';
	line[1] = NULL;
	return (line);
}

int		ft_stock(char *buff, char **rstr, int ret, int j)
{
	int	c;

	c = 0;
	rstr[j] = ft_strdup(buff);
	while (rstr[j][c] && rstr[j][c] != '\n' && ret > 0)
	{
		ret--;
		c++;
	}
	return (c);
}

int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE];
	char		**rstr;
	int			ret;
	static int	i = 0;
	int			j;
	int			stop;
	int			t;

	stop = 0;
	j = 0;
	rstr = (char**)malloc(sizeof(char*) * 200);
	while ((ret = read(fd, buff, BUFF_SIZE)) && stop == 0)
	{
		buff[ret] = '\0';
		i += ft_stock(buff, rstr, ret, j);
		t = 0;
		while (rstr[j][t])
		{
			if (rstr[j][t] == '\n')
				stop = 1;
			t++;
		}
		j++;
	}
	rstr[j] = NULL;
	line = ft_make_line(line, rstr, i, BUFF_SIZE);
	printf("%d\n", i);
	printf("%s\n", line[0]);
	return (0);
}

int		main(int argc, char **argv)
{
	char **line;
	int	fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	line = NULL;
	get_next_line(fd, line);
	return (0);
}
