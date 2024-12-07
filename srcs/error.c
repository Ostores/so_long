/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 23:36:48 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/29 14:11:04 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	free_map(t_asset *asset)
{
	int	i;

	i = 0;
	while (i < asset->map_height)
	{
		free(asset->map[i]);
		i++;
	}
	free(asset->map);
}

static void	free_textures(t_asset *asset)
{
	if (asset->p_top_64)
		mlx_destroy_image(asset->mlx, asset->p_top_64);
	if (asset->p_bot_64)
		mlx_destroy_image(asset->mlx, asset->p_bot_64);
	if (asset->p_left_64)
		mlx_destroy_image(asset->mlx, asset->p_left_64);
	if (asset->p_right_64)
		mlx_destroy_image(asset->mlx, asset->p_right_64);
	if (asset->space_64)
		mlx_destroy_image(asset->mlx, asset->space_64);
	if (asset->wall_64)
		mlx_destroy_image(asset->mlx, asset->wall_64);
	if (asset->exit_64)
		mlx_destroy_image(asset->mlx, asset->exit_64);
	if (asset->co_64)
		mlx_destroy_image(asset->mlx, asset->co_64);
}

static void	free_window(t_asset *asset)
{
	if (asset->win)
		mlx_destroy_window(asset->mlx, asset->win);
}

static void	display_error_and_exit(t_asset *asset, char *str)
{
	if (str)
		ft_printf("Error\n%s\n", str);
	free_map(asset);
	free_textures(asset);
	free_window(asset);
	exit(1);
}

void	free_and_exit(t_asset *asset, char *str)
{
	if (!str)
		exit(0);
	display_error_and_exit(asset, str);
}
