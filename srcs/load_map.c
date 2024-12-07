/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:08:42 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/29 14:04:51 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	calculate_dimensions_and_directions(t_asset *asset)
{
	asset->width = asset->map_width * 64;
	asset->height = asset->map_height * 64;
	asset->directions[0][0] = -1;
	asset->directions[0][1] = 0;
	asset->directions[1][0] = 1;
	asset->directions[1][1] = 0;
	asset->directions[2][0] = 0;
	asset->directions[2][1] = -1;
	asset->directions[3][0] = 0;
	asset->directions[3][1] = 1;
}

int	allocate_map_memory(t_asset *asset, int map_height)
{
	asset->map = (char **)malloc(sizeof(char *) * map_height);
	if (!asset->map)
	{
		perror("Error\nMemory allocation failed for map ");
		return (0);
	}
	return (1);
}

void	load_map_data(t_asset *asset)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(asset->fd_map, O_RDONLY);
	lseek(fd, 0, SEEK_SET);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		asset->map[y] = line;
		y++;
	}
	free(line);
	close(fd);
	asset->map_height = y;
}

void	load_map(t_asset *asset)
{
	int	fd;
	int	map_height;

	fd = 0;
	map_height = open_and_get_map_width(asset, fd);
	if (map_height > 22 || asset->map_width > 40)
	{
		ft_printf("Error\nMap is too big\n");
		exit(1);
	}
	if (map_height == -1 || map_height == 0)
	{
		ft_printf("Error\nMap is empty\n");
		exit(1);
	}
	if (!allocate_map_memory(asset, map_height))
		exit(1);
	load_map_data(asset);
	calculate_dimensions_and_directions(asset);
}
