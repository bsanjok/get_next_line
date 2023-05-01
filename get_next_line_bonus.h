/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbhatta <sbhatta@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:46:18 by sbhatta           #+#    #+#             */
/*   Updated: 2023/04/25 12:42:24 by sbhatta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef FD_MAX
#  define FD_MAX 1024
# endif

char			*get_next_line(int fd);
size_t			ft_strlen_bonus(const char *s);
char			*ft_strchr_bonus(const char *s, int c);
size_t			ft_strlcpy_bonus(char *dst, const char *src, size_t dstsize);
void			*ft_memset_bonus(void *b, int c, size_t len);
char			*ft_strjoin_bonus(char *buffer, char	*to_add);
size_t			ft_strlcat_bonus(char *dst, const char *src, size_t dstsize);
void			ft_free_bonus(char *buffer);

#endif