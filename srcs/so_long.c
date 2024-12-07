/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:46:55 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/29 14:12:54 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_asset *asset)
{
	mlx_destroy_window(asset->mlx, asset->win);
	exit(0);
	return (0);
}

static int	check_fd_map(t_asset *asset)
{
	int			i;
	int			res;
	const char	*fd_m;
	int			fd;

	fd_m = asset->fd_map;
	i = ft_strnstr(fd_m, ".ber", ft_strlen(fd_m));
	res = ft_strlen(fd_m) - i;
	fd = open(fd_m, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nCan't opening file ");
		exit(2);
	}
	if (res == 4)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_asset	asset;

	if (ac == 1)
		asset.fd_map = "map.ber";
	if (ac == 2)
		asset.fd_map = av[1];
	if (!check_fd_map(&asset))
	{
		ft_printf("Error\nFd is not a .ber\n");
		exit(1);
	}
	load_map(&asset);
	if (!init_assets(&asset))
		return (1);
	parsing_map(&asset);
	load_map(&asset);
	init_player_position(&asset);
	init_collectible(&asset);
	draw_map(&asset);
	mlx_key_hook(asset.win, key_press, &asset);
	mlx_hook(asset.win, 17, 0, close_window, &asset);
	mlx_loop(asset.mlx);
	return (0);
}
