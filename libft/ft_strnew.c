/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:03:43 by kbagot            #+#    #+#             */
/*   Updated: 2016/11/14 18:42:04 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strnew(size_t size)
{
	char	*mem;

	mem = (char*)malloc(sizeof(char) * size + 1);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, size + 1);
	return (mem);
}
