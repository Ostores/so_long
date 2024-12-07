/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 23:36:56 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/29 13:25:12 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	find_player_and_exit(t_asset *asset)
{
	int	i;
	int	j;

	i = 0;
	while (i < asset->map_height)
	{
		j = 0;
		while (j < asset->map_width)
		{
			if (asset->map[i][j] == 'P')
			{
				asset->x = i;
				asset->y = j;
			}
			if (asset->map[i][j] == 'E')
				asset->map[i][j] = 'E';
			j++;
		}
		i++;
	}
	if (asset->x == -1 || asset->y == -1)
		return (0);
	return (1);
}

static int	dfs(t_asset *asset, int x, int y)
{
	int	i;
	int	nx;
	int	ny;

	if (x < 0 || x >= asset->map_height || y < 0
		|| y >= asset->map_width || asset->map[x][y] == '1')
		return (0);
	if (asset->map[x][y] == 'E')
		return (1);
	asset->map[x][y] = '1';
	i = 0;
	while (i < 4)
	{
		nx = x + asset->directions[i][0];
		ny = y + asset->directions[i][1];
		if (dfs(asset, nx, ny))
			return (1);
		i++;
	}
	return (0);
}

static int	find_path_to_exit(t_asset *asset)
{
	if (!find_player_and_exit(asset))
		return (0);
	if (dfs(asset, asset->x, asset->y))
		return (1);
	return (0);
}

int	init_exit_acces(t_asset *asset)
{
	int	i;

	i = 0;
	load_map(asset);
	if (!find_path_to_exit(asset))
		return (0);
	while (i < asset->map_height)
	{
		free(asset->map[i]);
		i++;
	}
	free(asset->map);
	return (1);
}
