/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:45:28 by sbhatta           #+#    #+#             */
/*   Updated: 2023/04/25 12:57:12 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free_bonus(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
}

char	*ft_strjoin_bonus(char *result, char	*buffer_to_add)
{
	char	*result_join;
	size_t	s1len;
	size_t	s2len;

	if (!result)
	{
		result = malloc(1);
		if (!result)
			return (0);
		*result = '\0';
	}
	s1len = ft_strlen_bonus(result);
	s2len = ft_strlen_bonus(buffer_to_add);
	result_join = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (!result_join)
		return (ft_free_bonus(result), NULL);
	ft_strlcpy_bonus(result_join, result, (s1len + 1));
	ft_strlcat_bonus(result_join, buffer_to_add, (s2len + s1len + 1));
	free(result);
	return (result_join);
}

char	*ft_no_newline_b(char *buffer, char *result, int fd, int *read_bytes)
{
	while (!ft_strchr_bonus(buffer, '\n'))
	{
		result = ft_strjoin_bonus(result, buffer);
		if (!result)
			return (NULL);
		ft_memset_bonus(buffer, 0, ft_strlen_bonus(buffer) + 1);
		*read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (*read_bytes == 0)
			return (result);
		else if (*read_bytes == -1)
			return (ft_free_bonus(result), NULL);
		buffer[*read_bytes] = '\0';
	}
	return (result);
}

static char	*return_line_b(char *buffer, char *result, int fd, int read_bytes)
{
	char	*end;
	char	*to_join;

	if (!ft_strchr_bonus(buffer, '\n'))
	{
		result = ft_no_newline_b(buffer, result, fd, &read_bytes);
		if (read_bytes == 0)
			return (result);
		else if (read_bytes == -1)
			return (ft_free_bonus(result), NULL);
	}
	end = ft_strchr_bonus(buffer, '\n');
	to_join = malloc(end - buffer + 2);
	if (!to_join)
		return (NULL);
	ft_strlcpy_bonus(to_join, buffer, end - buffer + 2);
	result = ft_strjoin_bonus(result, to_join);
	free(to_join);
	if (!result)
		return (NULL);
	ft_memset_bonus(buffer, 0, end - buffer);
	ft_strlcpy_bonus(buffer, end + 1, ft_strlen_bonus(end) + 1);
	return (result);
}

char	*get_next_line(int fd)
{
	static char		buffer[FD_MAX][BUFFER_SIZE + 1];
	int				read_bytes;
	char			*result;

	if (BUFFER_SIZE < 1 || fd > 1024 || fd < 0)
		return (NULL);
	result = NULL;
	read_bytes = 0;
	if (!*buffer[fd])
	{
		read_bytes = read(fd, buffer[fd], BUFFER_SIZE);
		if (read_bytes <= 0)
			return (NULL);
		buffer[fd][read_bytes] = '\0';
	}
	return (return_line_b(buffer[fd], result, fd, read_bytes));
}
