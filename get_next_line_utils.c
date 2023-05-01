/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:46:05 by sbhatta           #+#    #+#             */
/*   Updated: 2023/04/21 13:31:47 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	a;
	char	*ptr;
	size_t	len;

	a = (char)c;
	ptr = NULL;
	len = ft_strlen((char *)s);
	if (a != '\0')
	{
		while (*s)
		{
			if (*s == a)
			{
				ptr = (char *)s;
				break ;
			}
			s++;
		}
	}
	else
		ptr = (char *)s + len;
	return (ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	count;

	len = ft_strlen((char *)src);
	count = 0;
	if (dstsize != 0)
	{
		while (count <= (dstsize - 2) && src[count] != '\0')
		{
			if (dstsize != 1)
			{
				dst[count] = src[count];
				count++;
			}
			else
				break ;
		}
		dst[count] = '\0';
	}
	return (len);
}

void	*ft_memset(void *b, int c, size_t len)
{
	char	*a;

	a = (char *)b;
	while (len --)
		*a++ = (char)c;
	return (b);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	res;

	if ((!dst && dstsize == 0))
		return (0);
	dlen = ft_strlen(dst);
	slen = ft_strlen((char *)src);
	if (dstsize > dlen)
		res = slen + dlen;
	else
	{
		res = slen + dstsize;
		return (res);
	}
	dst = dst + dlen;
	while (*src && ++dlen < dstsize)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (res);
}
