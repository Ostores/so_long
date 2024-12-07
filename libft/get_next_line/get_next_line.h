/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:32:48 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/29 00:21:38 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

size_t			ft_strlenn(char const *str);
char			*ft_strchrr(char const *str, int c);
char			*ft_strcpyy(char *dest, const char *src);
char			*ft_strjoinn(char *s1, char const *s2);
char			*get_next_line(int fd);

#endif
