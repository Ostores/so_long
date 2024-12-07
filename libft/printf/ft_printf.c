/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:36:42 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/27 22:02:44 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(va_list args, const char str)
{
	int	i;

	i = 0;
	if (str == 'c')
		i += ft_putchar((va_arg(args, int)));
	else if (str == 's')
		i += ft_putstr((va_arg(args, char *)));
	else if (str == 'p')
		i += ft_p((va_arg(args, uintptr_t)));
	else if (str == 'd' || str == 'i')
		i += ft_put_nbr((va_arg(args, int)));
	else if (str == 'u')
		i += ft_put_unsigned_nbr((va_arg(args, unsigned int)));
	else if (str == 'x')
		i += ft_exa((va_arg(args, unsigned int)));
	else if (str == 'X')
		i += ft_exa_up((va_arg(args, unsigned int)));
	else if (str == '%')
		i += ft_putchar('%');
	else
		i += ft_putchar(str);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		place;
	int		i;

	i = 0;
	place = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			place += ft_convert(args, str[++i]);
		}
		else
		{
			place += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (place);
}
