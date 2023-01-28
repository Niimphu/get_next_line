/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:39:18 by yiwong            #+#    #+#             */
/*   Updated: 2023/01/28 19:40:24 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*c;
	int			bytes_read;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	buff[BUFFER_SIZE] = 0;
	c = 0;
	while (c != '\n' && c)
	{
		bytes_read = read(fd, &buff, BUFFER_SIZE);
		*buff++ = c;
	}
	return (buff);
}
