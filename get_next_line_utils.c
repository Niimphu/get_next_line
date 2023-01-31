/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiwong <yiwong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:28:36 by yiwong            #+#    #+#             */
/*   Updated: 2023/01/31 16:37:48 by yiwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strlcpy(char *dst, const char *src, int size)
{
	char	*s;
	int		slen;
	int		i;

	if (!dst || !src)
		return ((int) NULL);
	slen = ft_strlen(src);
	if (!size || size == 0)
		return (slen);
	s = (char *)src;
	i = 0;
	while (s[i] && i < size)
	{
		dst[i] = s[i];
		i++;
	}
	if (size <= slen)
		dst[size - 1] = '\0';
	else if (size != 0)
		dst[i] = '\0';
	return (slen);
}

int	ft_strlcat(char *dst, const char *src, int size)
{
	int		dstlen;
	int		srclen;
	char	*dstend;

	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	dstlen = ft_strlen(dst);
	if (size < dstlen)
		return (srclen + size);
	dstend = dst + dstlen;
	ft_strlcpy(dstend, src, size - dstlen);
	return (dstlen + srclen);
}

char	*ft_strdup(const char *s)
{
	int		slen;
	char	*src;
	char	*dst;

	if (!s || s == 0)
		return (NULL);
	src = (char *)s;
	slen = ft_strlen(src);
	dst = malloc(sizeof(char) * (slen + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, src, slen);
	dst[slen] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	int		slen1;
	int		slen2;

	if (!s1 && !s2)
		return (ft_strdup(""));
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	slen1 = ft_strlen(s1);
	slen2 = ft_strlen(s2);
	r = malloc(sizeof(char) * (slen1 + slen2 + 1));
	if (!r)
		return (NULL);
	ft_strlcpy(r, s1, slen1 + 1);
	ft_strlcat(r + slen1, s2, slen2 + 1);
	return (r);
}
