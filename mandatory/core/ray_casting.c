/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:36:01 by jmenard           #+#    #+#             */
/*   Updated: 2025/02/08 18:39:50 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_pixel_color(char *texture, int x, int y)
{
	int		color;
	char	*pixel;
	t_image	*img;

	img = get_mlx(NULL)->image;
	pixel = texture + (y * img->tex_width + x) * 4;
	color = *(int *)pixel;
	return (color);
}

int	is_hit(int hit)
{
	t_mlx	*mlx;
	t_ray	*ray;

	mlx = get_mlx(NULL);
	ray = mlx->ray;
	while (hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_x;
			ray->j_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_y;
			ray->j_y += ray->step_y;
			ray->side = 1;
		}
		if (mlx->data->map2d[ray->j_y][ray->j_x] == '1'
			|| mlx->data->map2d[ray->j_y][ray->j_x] == 'D')
			hit = 1;
	}
	return (hit);
}

void	draw_pixel(t_mlx *mlx_struct, t_ray *ray, int i)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->j_x - mlx_struct->player->pos_x + (1
					- ray->step_x) / 2) / ray->ray_x;
	else
		ray->perp_wall_dist = (ray->j_y - mlx_struct->player->pos_y + (1
					- ray->step_y) / 2) / ray->ray_y;
	if (ray->perp_wall_dist < 0.0001)
		ray->perp_wall_dist = 0.0001;
	ray->line_height = (int)(SCREEN_H / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + SCREEN_H / 2;
	ray->draw_end = ray->line_height / 2 + SCREEN_H / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= SCREEN_H)
		ray->draw_end = SCREEN_H - 1;
	draw_c_f(i);
	draw_column(i, ray->draw_start, ray->draw_end);
}

void	chose_dir_and_draw(t_mlx *mlx_struct, t_ray *ray, int i)
{
	if (ray->ray_x < 0)
		ray->side_dist_x = (mlx_struct->player->pos_x - ray->j_x)
			* ray->delta_x;
	else
		ray->side_dist_x = (ray->j_x + 1.0 - mlx_struct->player->pos_x)
			* ray->delta_x;
	if (ray->ray_y < 0)
		ray->side_dist_y = (mlx_struct->player->pos_y - ray->j_y)
			* ray->delta_y;
	else
		ray->side_dist_y = (ray->j_y + 1.0 - mlx_struct->player->pos_y)
			* ray->delta_y;
	if (ray->ray_x < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	if (ray->ray_y < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
	if (is_hit(0) == 1)
		draw_pixel(mlx_struct, ray, i);
}

int	cast_ray(void)
{
	int		i;
	t_mlx	*mlx_struct;
	t_ray	*ray;

	i = 0;
	mlx_struct = get_mlx(NULL);
	ray = mlx_struct->ray;
	while (i < SCREEN_W)
	{
		ray->dir_x = cos(mlx_struct->player->angle);
		ray->dir_y = sin(mlx_struct->player->angle);
		ray->plan_x = -ray->dir_y * tan(FOV / 2);
		ray->plan_y = ray->dir_x * tan(FOV / 2);
		ray->camera_x = 2 * (double)i / (double)SCREEN_W - 1;
		ray->ray_x = ray->dir_x + ray->plan_x * ray->camera_x;
		ray->ray_y = ray->dir_y + ray->plan_y * ray->camera_x;
		ray->delta_x = fabs(1.0 / (ray->ray_x + 0.0001));
		ray->delta_y = fabs(1.0 / (ray->ray_y + 0.0001));
		ray->j_x = (int)mlx_struct->player->pos_x;
		ray->j_y = (int)mlx_struct->player->pos_y;
		chose_dir_and_draw(mlx_struct, ray, i);
		i++;
	}
	return (0);
}
