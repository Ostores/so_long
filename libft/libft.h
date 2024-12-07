/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:54:18 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/29 12:49:50 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "./get_next_line/get_next_line.h"
# include "./printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>

size_t	ft_strlen(const char *str);
int		ft_strnstr(const char *str, const char *find, size_t len);

#endif
