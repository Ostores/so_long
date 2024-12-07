/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:21:59 by emlinott          #+#    #+#             */
/*   Updated: 2024/12/06 15:59:14 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	open_file_and_check(t_asset *asset)
{
	int	fd;

	fd = open(asset->fd_map, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nCan't open file ");
		return (-1);
	}
	return (fd);
}

static int	check_line_width(char *line, int *map_width, int y, t_asset *asset)
{
	int	x;

	x = strlen(line);
	if (line[x - 1] == '\n')
		x--;
	if (*map_width == -1)
	{
		*map_width = x;
		asset->map_width = *map_width;
	}
	else if (x != *map_width)
	{
		ft_printf("Error\nSize of line %d.\n", y + 1);
		free(line);
		exit(1);
	}
	return (0);
}

int	open_and_get_map_width(t_asset *asset, int fd)
{
	int			y;
	char		*line;
	static int	map_width = -1;

	y = 0;
	fd = open_file_and_check(asset);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (check_line_width(line, &map_width, y, asset) == -1)
		{
			free(line);
			close(fd);
			exit(1);
		}
		free(line);
		y++;
	}
	free(line);
	close(fd);
	return (y);
}


int	open_and_get_map_width(t_asset *asset, int fd)
{
	int			y;
	char		*line;

	y = 0;
	fd = open_file_and_check(asset);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		y++;
	}
	free(line);
	close(fd);
	return (y);
}