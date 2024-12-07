/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:50:17 by emlinott          #+#    #+#             */
/*   Updated: 2024/12/07 16:15:50 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*get_texture(t_asset *asset, char map_char)
{
	if (map_char == '1')
		return (asset->wall_64);
	else if (map_char == 'P')
		return (asset->p_top_64);
	else if (map_char == 'L')
		return (asset->p_left_64);
	else if (map_char == 'B')
		return (asset->p_bot_64);
	else if (map_char == 'R')
		return (asset->p_right_64);
	else if (map_char == 'E')
		return (asset->exit_64);
	else if (map_char == 'C')
		return (asset->co_64);
	else
		return (asset->space_64);
}

void	draw_map(t_asset *asset)
{
	int		x;
	int		y;
	void	*texture;

	y = 0;
	while (y < asset->map_height)
	{
		x = 0;
		while (x < asset->map_width)
		{
			texture = get_texture(asset, asset->map[y][x]);
			mlx_put_image_to_window(asset->mlx, asset->win, texture,
				x * 64, y * 64);
			x++;
		}
		y++;
	}
}

