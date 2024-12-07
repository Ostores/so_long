/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:51:54 by emlinott          #+#    #+#             */
/*   Updated: 2024/12/07 16:16:18 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	move_player(t_asset *asset, int new_x, int new_y, int pos)
{
	static int	move = 1;

	ft_printf("Move : %d\n", move++);
	if (asset->map[new_y][new_x] == 'C')
		asset->collectible--;
	asset->map[asset->futur_pos_y][asset->futur_pos_x] = '0';
	if (pos == 1)
		asset->map[new_y][new_x] = 'T';
	else if (pos == 2)
		asset->map[new_y][new_x] = 'L';
	else if (pos == 3)
		asset->map[new_y][new_x] = 'B';
	else if (pos == 4)
		asset->map[new_y][new_x] = 'R';
	else if (pos == 5)
		return ;
	asset->futur_pos_x = new_x;
	asset->futur_pos_y = new_y;
	mlx_clear_window(asset->mlx, asset->win);
	draw_map(asset);
}

void	handle_move(t_asset *asset, int new_x, int new_y, int pos)
{
	if (asset->map[new_y][new_x] == '0' || asset->map[new_y][new_x] == 'C')
		move_player(asset, new_x, new_y, pos);
	else if (asset->map[new_y][new_x] == 'E' && asset->collectible == 0)
	{
		move_player(asset, new_x, new_y, '5');
		free_and_exit(asset, NULL);
	}
}

int	key_to_pos(int keycode)
{
	if (keycode == 13)
		return (1);
	else if (keycode == 0)
		return (2);
	else if (keycode == 1)
		return (3);
	else if (keycode == 2)
		return (4);
	return (0);
}

int	key_press(int keycode, t_asset *asset)
{
	int	new_x;
	int	new_y;
	int	pos;

	new_x = asset->futur_pos_x;
	new_y = asset->futur_pos_y;
	if (keycode == 53)
		exit(0);
	if (keycode == 13)
		new_y--;
	else if (keycode == 0)
		new_x--;
	else if (keycode == 1)
		new_y++;
	else if (keycode == 2)
		new_x++;
	pos = key_to_pos(keycode);
	handle_move(asset, new_x, new_y, pos);
	return (0);
}