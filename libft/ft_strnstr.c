/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:39:35 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/29 13:36:42 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str && len == 0)
		return (0);
	if (find[i] == '\0')
		return (i);
	while (str[i])
	{
		while (str[i + j] == find[j] && str[i + j] != '\0' && i + j < len)
			j++;
		if (find[j] == '\0')
			return (i);
		i++;
		j = 0;
	}
	return (0);
}
