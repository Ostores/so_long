/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_co.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 23:36:53 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/29 13:25:33 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	find_player_and_exit_co(int i, t_asset *asset)
{
	int	j;

	asset->nb_co = 0;
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
			if (asset->map[i][j] == 'C')
				asset->nb_co++;
			j++;
		}
		i++;
	}
	if (asset->x == -1 || asset->y == -1)
		return (0);
	return (1);
}

static int	dfs_co(t_asset *asset, int x, int y, int *collectibles_found)
{
	int	i;
	int	nx;
	int	ny;

	if (x < 0 || x >= asset->map_height || y < 0
		|| y >= asset->map_width || asset->map[x][y] == '1')
		return (0);
	if (asset->map[x][y] == 'C')
		(*collectibles_found)++;
	asset->map[x][y] = '1';
	i = 0;
	while (i < 4)
	{
		nx = x + asset->directions[i][0];
		ny = y + asset->directions[i][1];
		dfs_co(asset, nx, ny, collectibles_found);
		i++;
	}
	return (0);
}

static int	find_path_to_exit_and_collectibles(t_asset *asset)
{
	int	i;
	int	collectibles_found;

	i = 0;
	collectibles_found = 0;
	if (!find_player_and_exit_co(i, asset))
		return (0);
	dfs_co(asset, asset->x, asset->y, &collectibles_found);
	if (collectibles_found == asset->nb_co)
		return (1);
	return (0);
}

int	init_collectible_acces(t_asset *asset)
{
	int	i;

	i = 0;
	load_map(asset);
	if (!find_path_to_exit_and_collectibles(asset))
		return (0);
	while (i < asset->map_height)
	{
		free(asset->map[i]);
		i++;
	}
	free(asset->map);
	return (1);
}
