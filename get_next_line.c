/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:37:51 by kbagot            #+#    #+#             */
/*   Updated: 2016/12/12 20:50:41 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_makeline(char *lst, char **line)
{
	int		i;

	i = 0;
	while (lst[i] != '\n')
		i++;
	lst[i] = '\0';
	line = (char**)malloc(sizeof(char*) * 2);
	line[1] = NULL;
	line[0]	= ft_strnew(i);
	ft_strcpy(line[0], lst);
	ft_strcpy(lst, &lst[i + 1]);
	printf("save : %s|||||\n", line[0]);
	return (lst);
}

int		get_next_line(const int fd, char **line)
{
	char			*buff;
	static t_list	*rstr = NULL;
	char			*lst;
	int				ret;
	char			*tmp;

	lst = NULL;
	if (rstr == NULL)
	{//if  fd non existent
		rstr = ft_lstnew(lst, fd);
		rstr->rstr = ft_strnew(BUFF_SIZE);
	}
	buff = ft_strnew(BUFF_SIZE);
	tmp = NULL;
	while (tmp == NULL)
	{
		ret = read(fd, buff, BUFF_SIZE);
		tmp = ft_strchr(buff, '\n');
		rstr->rstr = ft_strjoin(rstr->rstr, buff);
	}
//	printf("read : %s|||||\n", rstr->rstr);
	rstr->rstr = ft_makeline(rstr->rstr, line);
//	printf("save : %s|||||\n", rstr->rstr);
	return (0);
}

int		main(int argc, char **argv)
{
	char **line;
	int	fd;
	int lol;

	lol = 5;
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	line = NULL;
	while (lol-- > 1)
		get_next_line(fd, line);
	return (0);
}
