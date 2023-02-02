/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:41:58 by yiwong            #+#    #+#             */
/*   Updated: 2023/02/01 18:41:58 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_split(char *buff2, char *buff)
{
	char	*r;
	int		i;
	int		j;

	if (!gnl_findnl(buff2))
		return (gnl_join(buff, buff2));
	if (*buff)
		buff2 = gnl_join(buff, buff2);
	r = gnl_calloc(gnl_strlen(buff2, '\n') + 2, sizeof(char));
	if (!r)
		return (NULL);
	i = 0;
	while (buff2[i++] != '\n')
		r[i] = buff2[i];
	// buff = gnl_calloc(gnl_strlen(buff2 + i + 1, '\0'), sizeof(char));
	// if (!buff)
	// 	return (NULL);
	j = 0;
	while (buff2[i] && buff[j])
		buff[j++] = buff2[i++];
	while (buff[j])
		buff[j++] = '\0';
	buff = buff2;
	if (buff2)
		free(buff2);
	buff2 = NULL;
	return (r);
}

char	*gnl_join(char *buff, char *read_line)
{
	char	*r;
	int		slenb;
	int		slenrl;
	int		i;

	if (!buff)
		return (read_line);
	i = 0;
	slenb = gnl_strlen(buff, '\0');
	slenrl = gnl_strlen(read_line, '\0');
	r = gnl_calloc((slenb + slenrl + 1), sizeof(char));
	if (!r)
		return (NULL);
	while (*buff)
		r[i++] = *buff++;
	while (*read_line)
		r[i++] = *read_line++;
	return (r);
}

char	*gnl_read(char *buff2, int bytes_read, int fd)
{
	char	read_line[BUFFER_SIZE + 1];

	while (!gnl_findnl(buff2) && bytes_read > 0)
	{
		bytes_read = read(fd, read_line, BUFFER_SIZE);
		buff2 = gnl_join(buff2, read_line);
		if (!buff2)
			return (NULL);
	}
	return (buff2);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*r;
	char 		*read_line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buff)
		{
			free(buff);
			buff = NULL;
		}
		return (NULL);
	}
	if (!buff)
	{
		buff = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buff)
			return (NULL);
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	else
		bytes_read = 1;
	read_line = gnl_read(buff, bytes_read, fd);
	if (!read_line)
		return (NULL);
	r = gnl_split(read_line, buff);
	free(read_line);
	return (r);
}
