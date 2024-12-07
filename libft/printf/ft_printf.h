/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:52:40 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/27 22:21:26 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_put_nbr(int nb);
int		ft_put_unsigned_nbr(unsigned int nb);
int		ft_flag(const char *str, int i);

int		ft_exa_up(unsigned int nb);
int		ft_exa(unsigned int nb);
int		ft_put_ptr(uintptr_t ptr);
int		ft_p(uintptr_t ptr);

int		ft_convert(va_list args, const char str);
int		ft_flag(const char *str, int i);
int		ft_printf(const char *str, ...);

#endif