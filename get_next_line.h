/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:11:42 by kbagot            #+#    #+#             */
/*   Updated: 2016/12/08 19:41:11 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"//tmp open
# include "stdio.h"//tmp printf
# define BUFF_SIZE 4

typedef struct	s_list
{
	void	*content;
	size_t	content_size;
	struct s_list	*next;
}				t_list;

int		get_next_line(const int fd, char **line);
char	*ft_strdup(const char *s1);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);

#endif
