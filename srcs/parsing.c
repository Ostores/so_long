/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 23:37:02 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/29 14:11:29 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	arg_is_ok(char **map, int map_height, int map_width)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_height)
	{
		j = 0;
		while (j < map_width)
		{
			if (map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'C' ||
				map[i][j] == 'P' || map[i][j] == 'E' || map[i][j] == '\n')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

static int	can_we_exit(char **map, int map_height, int map_width)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	exit = 0;
	while (i < map_height)
	{
		j = 0;
		while (j < map_width)
		{
			if (map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (exit == 1)
		return (1);
	return (0);
}

static int	can_we_play(char **map, int map_height, int map_width)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (i < map_height)
	{
		j = 0;
		while (j < map_width)
		{
			if (map[i][j] == 'P')
				player++;
			j++;
		}
		i++;
	}
	if (player == 1)
		return (1);
	return (0);
}

static int	count_collectibles(t_asset *asset)
{
	char	**map;
	int		height;
	int		collectibles;
	int		i;
	char	*line;

	collectibles = 0;
	map = asset->map;
	height = asset->map_height;
	i = 0;
	while (i < height)
	{
		line = map[i];
		while (*line)
		{
			if (*line == 'C')
				collectibles++;
			line++;
		}
		i++;
	}
	if (collectibles <= 0)
		return (0);
	asset->nb_co = collectibles;
	return (1);
}

int	parsing_map(t_asset *asset)
{
	char	**map;
	int		height;
	int		width;

	map = asset->map;
	height = asset->map_height;
	width = asset->map_width;
	if (!can_we_play(map, height, width))
		free_and_exit(asset, "Not found Player");
	if (!can_we_exit(map, height, width))
		free_and_exit(asset, "Not found Exit");
	if (!arg_is_ok(map, height, width))
		free_and_exit(asset, "Args in map");
	if (!count_collectibles(asset))
		free_and_exit(asset, "No Collectible");
	if (!find_wall(asset))
		free_and_exit(asset, "Wall");
	if (!init_exit_acces(asset))
		free_and_exit(asset, "Exit access");
	if (!init_collectible_acces(asset))
		free_and_exit(asset, "Collectible access");
	return (0);
}
