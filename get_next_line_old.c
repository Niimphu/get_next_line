/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:39:18 by yiwong            #+#    #+#             */
/*   Updated: 2023/01/31 18:48:57 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_rline(char *buff)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strdup(buff);
	while (temp[i - 1] != '\n')
		i++;
	free(temp + i + 1);
	return (temp);
}

int	find_nl(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*readline;
	char		*r;
	int			bytes_read;
	int			nl_index;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buff)
			free(buff);
		buff = NULL;
		return (NULL);
	}
	readline = malloc(BUFFER_SIZE + 1);
	if (!readline)
		return (NULL);
	readline[BUFFER_SIZE] = '\0';
	bytes_read = read(fd, readline, BUFFER_SIZE);
	if (!buff && bytes_read)
		buff = ft_strdup(readline);
	else if (bytes_read)
		ft_strjoin(buff, readline);
	nl_index = find_nl(readline);
	while (!nl_index && bytes_read > 0)
	{
		bytes_read = read(fd, readline, BUFFER_SIZE);
		buff = ft_strjoin(buff, readline);
		nl_index = find_nl(readline);
	}
	free(readline);
	if (bytes_read == 0)
		return (buff);
	r = ft_rline(buff);
	buff = find_nl(buff) + 1;
	return (r);
}
