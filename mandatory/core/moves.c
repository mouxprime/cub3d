/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:33:03 by mianni            #+#    #+#             */
/*   Updated: 2025/02/21 11:33:53 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_door_message(t_mlx *mlx_struct)
{
	int	x;
	int	y;
	int	color;

	x = 20;
	y = SCREEN_H - 40;
	color = 0xFFFFFF;
	mlx_string_put(mlx_struct->mlx_p, mlx_struct->mlx_win, x, y, color,
		"Appuyez sur 'O' pour ouvrir la porte");
}

bool	check_door(t_mlx *mlx_struct)
{
	int		pos_x;
	int		pos_y;
	char	**map;

	pos_x = (int)mlx_struct->player->pos_x;
	pos_y = (int)mlx_struct->player->pos_y;
	map = mlx_struct->data->map2d;
	if (map[pos_y][pos_x] == 'D' || map[pos_y + 1][pos_x] == 'D' || map[pos_y
		- 1][pos_x] == 'D' || map[pos_y][pos_x + 1] == 'D' || map[pos_y][pos_x
		- 1] == 'D')
	{
		print_door_message(mlx_struct);
		return (true);
	}
	return (false);
}

int	key_press(int keycode, t_mlx *mlx_struct)
{
	if (keycode == 65505)
		mlx_struct->speed = mlx_struct->speed * 2.5;
	if (keycode == 'w' || keycode == 'W')
		mlx_struct->keys.w = 1;
	if (keycode == 'a' || keycode == 'A')
		mlx_struct->keys.a = 1;
	if (keycode == 's' || keycode == 'S')
		mlx_struct->keys.s = 1;
	if (keycode == 'd' || keycode == 'D')
		mlx_struct->keys.d = 1;
	if (keycode == 65362)
		mlx_struct->keys.up = 1;
	if (keycode == 65364)
		mlx_struct->keys.down = 1;
	if (keycode == 65361)
		mlx_struct->keys.left = 1;
	if (keycode == 65363)
		mlx_struct->keys.right = 1;
	if (keycode == 65307)
		destroy_window(mlx_struct);
	return (0);
}

int	key_release(int keycode, t_mlx *mlx_struct)
{
	if (keycode == 65505)
		mlx_struct->speed = mlx_struct->speed / 2.5;
	if (keycode == 'o' || keycode == 'O')
		close_or_open_door(mlx_struct);
	if (keycode == 'w' || keycode == 'W')
		mlx_struct->keys.w = 0;
	if (keycode == 'a' || keycode == 'A')
		mlx_struct->keys.a = 0;
	if (keycode == 's' || keycode == 'S')
		mlx_struct->keys.s = 0;
	if (keycode == 'd' || keycode == 'D')
		mlx_struct->keys.d = 0;
	if (keycode == 65362)
		mlx_struct->keys.up = 0;
	if (keycode == 65364)
		mlx_struct->keys.down = 0;
	if (keycode == 65361)
		mlx_struct->keys.left = 0;
	if (keycode == 65363)
		mlx_struct->keys.right = 0;
	return (0);
}

double	get_view_angle(t_mlx *mlx_struct)
{
	return (mlx_struct->player->angle);
}
