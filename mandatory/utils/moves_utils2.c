/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:36:27 by mianni            #+#    #+#             */
/*   Updated: 2025/02/08 18:36:27 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	player_near_door(t_mlx *mlx_struct)
{
	int	door_x;
	int	door_y;

	door_x = mlx_struct->data->door_width;
	door_y = mlx_struct->data->door_height;
	if ((int)mlx_struct->player->pos_x == door_x
		&& (int)mlx_struct->player->pos_y == door_y + 1)
		return (true);
	if ((int)mlx_struct->player->pos_x == door_x
		&& (int)mlx_struct->player->pos_y == door_y - 1)
		return (true);
	if ((int)mlx_struct->player->pos_x == door_x + 1
		&& (int)mlx_struct->player->pos_y == door_y)
		return (true);
	if ((int)mlx_struct->player->pos_x == door_x - 1
		&& (int)mlx_struct->player->pos_y == door_y)
		return (true);
	return (false);
}

void	close_or_open_door(t_mlx *mlx_struct)
{
	char	**map;
	int		pos_x;
	int		pos_y;

	map = mlx_struct->data->map2d;
	pos_x = mlx_struct->player->pos_x;
	pos_y = mlx_struct->player->pos_y;
	if (map[pos_y][pos_x] == 'D' || map[pos_y + 1][pos_x] == 'D' || map[pos_y
		- 1][pos_x] == 'D' || map[pos_y][pos_x + 1] == 'D'
		|| map[pos_y][pos_x - 1] == 'D')
		mlx_struct->data->map2d[mlx_struct->data->door_height]
		[mlx_struct->data->door_width] = '0';
	else if (mlx_struct->data->map2d[mlx_struct->data->door_height]
		[mlx_struct->data->door_width] == '0'
		&& player_near_door(mlx_struct) == true)
		mlx_struct->data->map2d[mlx_struct->data->door_height]
		[mlx_struct->data->door_width] = 'D';
}

int	is_walkable(char **map, double x, double y)
{
	if (map[(int)(y - PLAYER_RADIUS)][(int)(x - PLAYER_RADIUS)] == '1' ||
		map[(int)(y - PLAYER_RADIUS)][(int)(x + PLAYER_RADIUS)] == '1' ||
		map[(int)(y + PLAYER_RADIUS)][(int)(x - PLAYER_RADIUS)] == '1' ||
		map[(int)(y + PLAYER_RADIUS)][(int)(x + PLAYER_RADIUS)] == '1' ||
		map[(int)y][(int)x] == '1' || map[(int)y][(int)x] == 'D')
		return (0);
	return (1);
}
