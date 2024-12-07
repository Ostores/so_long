/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:55:50 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/27 22:21:03 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// size_t	ft_strlenn(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

int	ft_putchar(char c)
{
	int	i;

	i = 0;
	i += write(1, &c, 1);
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_put_nbr(int nb)
{
	unsigned int	nbr;
	int				i;

	i = 0;
	if (nb < 0)
	{
		i += ft_putchar('-');
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr >= 10)
		i += ft_put_nbr(nbr / 10);
	i += ft_putchar(nbr % 10 + 48);
	return (i);
}

int	ft_put_unsigned_nbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 10)
		i += ft_put_unsigned_nbr(nb / 10);
	i += ft_putchar(nb % 10 + 48);
	return (i);
}
