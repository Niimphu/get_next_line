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

int	gnl_findnl(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i++] == '\n')
			return (i);
	}
	return (NULL);
}

char	*ft_calloc(int nmemb, int size)
{
	char	*r;
	int		i;

	r = malloc(nmemb * size);
	if (!r)
		return (NULL);
	i = 0;
	while (i < nmemb)
		r[i++] = 0;
	return (r);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*read;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buff)
			free(buff);
		buff = NULL;
		return (NULL);
	}
	if (!buff)
	{
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buff)
			return (NULL);
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	read = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while(bytes_read > 0 && !nl_index)
}
