/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:55:19 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/27 22:11:22 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_exa_up(unsigned int nb)
{
	char	*exa;
	int		i;

	i = 0;
	exa = "0123456789ABCDEF";
	if (nb >= 16)
		i += ft_exa_up(nb / 16);
	i += ft_putchar(exa[nb % 16]);
	return (i);
}

int	ft_exa(unsigned int nb)
{
	char	*exa;
	int		i;

	i = 0;
	exa = "0123456789abcdef";
	if (nb >= 16)
		i += ft_exa(nb / 16);
	i += ft_putchar(exa[nb % 16]);
	return (i);
}

int	ft_put_ptr(uintptr_t ptr)
{
	char	*str;
	int		i;

	i = 0;
	str = "0123456789abcdef";
	if (ptr >= 16)
		i += ft_put_ptr(ptr / 16);
	i += ft_putchar(str[ptr % 16]);
	return (i);
}

int	ft_p(uintptr_t ptr)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	if (i < 0)
		return (-1);
	i += ft_put_ptr(ptr);
	if (i < -1)
		return (-1);
	return (i);
}
