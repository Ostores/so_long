/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_asset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:55:27 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/29 15:06:13 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_player_position(t_asset *asset)
{
	int	y;
	int	x;

	y = 0;
	while (y < asset->map_height)
	{
		x = 0;
		while (x < asset->map_width)
		{
			if (asset->map[y][x] == 'P')
			{
				asset->futur_pos_x = x;
				asset->futur_pos_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	init_collectible(t_asset *asset)
{
	int	y;
	int	x;
	int	c;

	y = 0;
	c = 0;
	while (y < asset->map_height)
	{
		x = 0;
		while (x < asset->map_width)
		{
			if (asset->map[y][x] == 'C')
			{
				c++;
			}
			x++;
		}
		y++;
	}
	asset->collectible = c;
}

int	init_assets(t_asset *a)
{
	a->mlx = mlx_init();
	if (!a->mlx)
		error_exit("Error: Unable to initialize MinilibX\n");
	a->win = mlx_new_window(a->mlx, a->width, a->height, "So Long");
	if (!a->win)
		error_exit("Error: Unable to create windows\n");
	a->space_64 = mlx_xpm_file_to_image(a->mlx, "asset/sp.xpm",
			&a->i_x, &a->i_y);
	a->wall_64 = mlx_xpm_file_to_image(a->mlx, "asset/wl.xpm",
			&a->i_x, &a->i_y);
	a->exit_64 = mlx_xpm_file_to_image(a->mlx, "asset/exit.xpm",
			&a->i_x, &a->i_y);
	a->co_64 = mlx_xpm_file_to_image(a->mlx, "asset/co.xpm", &a->i_x, &a->i_y);
	a->p_top_64 = mlx_xpm_file_to_image(a->mlx, "asset/ptop.xpm",
			&a->i_x, &a->i_y);
	a->p_bot_64 = mlx_xpm_file_to_image(a->mlx, "asset/pbot.xpm",
			&a->i_x, &a->i_y);
	a->p_left_64 = mlx_xpm_file_to_image(a->mlx, "asset/pl.xpm",
			&a->i_x, &a->i_y);
	a->p_right_64 = mlx_xpm_file_to_image(a->mlx, "asset/pr.xpm",
			&a->i_x, &a->i_y);
	if (!a->p_right_64 || !a->p_left_64 || !a->p_bot_64 || !a->p_top_64
		|| !a->space_64 || !a->wall_64 || !a->exit_64 || !a->co_64)
		error_exit("Error\nUnable to load textures\n");
	return (1);
}

void	error_exit(char *str)
{
	ft_printf("Error\n%s\n", str);
	exit(2);
}