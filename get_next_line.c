/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:37:51 by kbagot            #+#    #+#             */
/*   Updated: 2016/12/15 16:41:12 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_makeline(char *lst, char **line)
{
	int		i;
	int		fin;

	fin = 0;
	i = 0;
	if (lst[i] != '\0' && lst)
	{
		while (lst[i] != '\n' && lst[i])
			i++;
		if (lst[i] == '\0')
			fin = 1;
		lst[i] = '\0';
		*line = ft_strnew(i);
		*line = ft_strcpy(*line, lst);
		lst = ft_strcpy(lst, &lst[i + 1]);
		if (fin == 1)
			lst[0] = '\0';
		return (1);
	}
	return (0);
}

static t_list	*ft_find_fd(t_list *rstr, int fd)
{
	t_list	*saverstr;
	t_list	*new;

	saverstr = rstr;
	if (rstr == NULL)
	{
		rstr = ft_lstnew(NULL, fd);
		rstr->content_size = fd;
		rstr->content = ft_strnew(BUFF_SIZE);
		return (rstr);
	}
	while (rstr)
	{
		if (rstr->content_size == (unsigned int)fd)
			return (rstr);
		rstr = rstr->next;
	}
	new = ft_lstnew(NULL, fd);
	new->content_size = fd;
	new->content = ft_strnew(BUFF_SIZE);
	ft_lstadd(&saverstr, new);
	return (saverstr);
}

int				get_next_line(const int fd, char **line)
{
	char			*buff;
	static t_list	*rstr = NULL;
	char			*stop;
	int				ret;

	stop = NULL;
	if (fd < 0 || !line)
		return (-1);
	rstr = ft_find_fd(rstr, fd);
	buff = ft_strnew(BUFF_SIZE);
	while (stop == NULL && (ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		ft_bzero(&buff[ret], BUFF_SIZE - ret);
		stop = ft_strchr(buff, '\n');
		rstr->content = ft_strjoin(rstr->content, buff);
	}
	free(buff);
	buff = NULL;
	if (ft_makeline(rstr->content, line))
		return (1);
	return (0);
}
