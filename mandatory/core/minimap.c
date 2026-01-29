/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:33:57 by mianni            #+#    #+#             */
/*   Updated: 2025/02/21 13:39:06 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_fov(t_mlx *mlx_struct, int i)
{
	t_ray	ray;
	double	ray_x;
	double	ray_y;

	while (i < MINIMAP_MAX_SIZE)
	{
		ray.dir_x = cos(mlx_struct->player->angle);
		ray.dir_y = sin(mlx_struct->player->angle);
		ray.plan_x = -ray.dir_y * tan(FOV / 2);
		ray.plan_y = ray.dir_x * tan(FOV / 2);
		ray.camera_x = 2 * (double)i / (double)MINIMAP_MAX_SIZE - 1;
		ray.ray_x = ray.dir_x + ray.plan_x * ray.camera_x;
		ray.ray_y = ray.dir_y + ray.plan_y * ray.camera_x;
		ray_x = mlx_struct->player->pos_x + 0.5;
		ray_y = mlx_struct->player->pos_y + 0.5;
		while (ray_x >= 0 && ray_x < mlx_struct->data->map_width && ray_y >= 0
			&& ray_y < mlx_struct->data->map_height
			&& mlx_struct->data->map2d[(int)ray_y][(int)ray_x] != '1'
			&& mlx_struct->data->map2d[(int)ray_y][(int)ray_x] != 'D')
			set_pixel(&ray_x, &ray_y, ray.ray_x, ray.ray_y);
		i++;
	}
}

void	draw_square(double x, double y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			set_pixel2(x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap_2(t_mlx *mlx)
{
	double	player_x;
	double	player_y;

	player_x = mlx->player->pos_x * mlx->minimap_scale;
	player_y = mlx->player->pos_y * mlx->minimap_scale;
	draw_fov(mlx, 0);
	draw_square(player_x, player_y, mlx->minimap_scale, 0xFF0000);
}

void	draw_minimap(t_mlx *mlx)
{
	int	x;
	int	y;

	calculate_minimap_scale(mlx);
	y = 0;
	while (y < mlx->data->map_height)
	{
		x = 0;
		while (x < (int)ft_strlen(mlx->data->map2d[y]))
		{
			if (mlx->data->map2d[y][x] == '0')
				draw_square(x * mlx->minimap_scale, y * mlx->minimap_scale,
					mlx->minimap_scale, 0xFFFFFF);
			else if (mlx->data->map2d[y][x] == 'Z')
				draw_square(x * mlx->minimap_scale, y * mlx->minimap_scale,
					mlx->minimap_scale, 0xF1B242);
			else
				draw_square(x * mlx->minimap_scale, y * mlx->minimap_scale,
					mlx->minimap_scale, 0x6B238E);
			x++;
		}
		y++;
	}
	draw_minimap_2(mlx);
}

int	load_minimap(void)
{
	t_mlx	*mlx_struct;

	mlx_struct = get_mlx(NULL);
	if (!mlx_struct || !mlx_struct->mlx_p || !mlx_struct->image)
		return (-1);
	draw_minimap(mlx_struct);
	mlx_put_image_to_window(mlx_struct->mlx_p, mlx_struct->mlx_win,
		mlx_struct->image->img, 0, 0);
	return (0);
}
