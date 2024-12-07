/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:17:58 by emlinott          #+#    #+#             */
/*   Updated: 2024/11/29 14:17:55 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "mlx.h"
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_asset
{
	void	*mlx;
	void	*win;
	char	*fd_map;
	void	*p_top_64;
	void	*p_bot_64;
	void	*p_left_64;
	void	*p_right_64;
	void	*space_64;
	void	*wall_64;
	void	*exit_64;
	void	*co_64;
	int		futur_pos_x;
	int		futur_pos_y;
	int		i_x;
	int		i_y;
	char	**map;
	int		map_height;
	int		map_width;
	int		collectible;
	int		width;
	int		height;
	int		x;
	int		y;
	int		nb_co;
	int		directions[4][2];
	bool	keys[256];
}	t_asset;

void	free_and_exit(t_asset *asset, char *str);
int		close_window(t_asset *asset);
void	error_exit(char *str);

void	load_map(t_asset *asset);
int		open_and_get_map_width(t_asset *asset, int fd);

int		find_way(char **map, int rows, int cols, t_asset *asset);
int		find_exit(char **map, int rows, int cols, t_asset *asset);

int		parsing_map(t_asset *asset);
int		init_assets(t_asset *a);
void	init_collectible(t_asset *asset);
void	init_player_position(t_asset *asset);
int		init_exit_acces(t_asset *asset);
int		init_collectible_acces(t_asset *asset);
int		find_wall(t_asset *asset);

int		key_press(int keycode, t_asset *asset);
void	draw_map(t_asset *asset);

int		main(int ac, char **av);

#endif
