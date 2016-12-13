/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:37:51 by kbagot            #+#    #+#             */
/*   Updated: 2016/12/13 15:21:17 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_makeline(char *lst, char **line)
{
	int		i;

	i = 0;
	while (lst[i] != '\n')
		i++;
	lst[i] = '\0';
	line[1] = NULL;
	line[0] = ft_strnew(i);
	line[0] = ft_strcpy(&line[0][0], lst);
	lst = ft_strcpy(lst, &lst[i + 1]);
	return (1);
}

t_list	*ft_find_fd(t_list *rstr, int fd)
{
	t_list	*saverstr;
	t_list	*new;

	saverstr = rstr;
	if (rstr == NULL)
	{
		rstr = ft_lstnew(NULL, fd);
		rstr->fdsave = fd;
		rstr->rstr = ft_strnew(BUFF_SIZE);
		return (rstr);
	}
	while (rstr)
	{
		if (rstr->fdsave == (unsigned int)fd)
			return (rstr);
		rstr = rstr->next;
	}
	new = ft_lstnew(NULL, fd);
	new->fdsave = fd;
	new->rstr = ft_strnew(BUFF_SIZE);
	ft_lstadd(&saverstr, new);
	return (saverstr);
}

int		get_next_line(const int fd, char **line)
{
	char			*buff;
	static t_list	*rstr = NULL;
	char			*stop;

	stop = NULL;
	rstr = ft_find_fd(rstr, fd);
	buff = ft_strnew(BUFF_SIZE);
	while (stop == NULL && read(fd, buff, BUFF_SIZE))
	{
		stop = ft_strchr(buff, '\n');
		rstr->rstr = ft_strjoin(rstr->rstr, buff);
	}
	if (ft_makeline(rstr->rstr, line))
		return (1);
	return (-1);
}

int		main(int argc, char **argv)
{
	char	**line;
	int		fd;
	int 	fd2;
	int		lol;

	lol = 8;
	if (argc)
	{
		line = (char**)malloc(sizeof(char*) * 2);
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		while (lol-- > 1)
		{
			get_next_line(fd2, line);
			printf("ligne : %s|||||\n", line[0]);
			get_next_line(fd, line);
			printf("ligne : %s|||||\n", line[0]);
		}
	}
	return (0);
}
