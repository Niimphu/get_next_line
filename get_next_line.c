/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:39:18 by yiwong            #+#    #+#             */
/*   Updated: 2023/01/30 20:24:44 by yiwong           ###   ########.fr       */
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

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*r;

	i = 0;
	r = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			r = ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		r = ((char *)s + i);
	return (r);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*readline;
	char		*r;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readline = malloc(BUFFER_SIZE + 1);
	if (!readline)
		return (NULL);
	readline[BUFFER_SIZE] = '\0';
	bytes_read = 1;
	while (!ft_strrchr(readline, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, readline, BUFFER_SIZE);
		if (!buff)
			buff = ft_strdup(readline);
		else
			buff = ft_strjoin(buff, readline);
		if (!buff)
			return (NULL);
	}
	if (bytes_read == 0)
		return (buff);
	r = ft_rline(buff);
	buff = ft_strrchr(buff, '\n') + 1;
	return (r);
}
