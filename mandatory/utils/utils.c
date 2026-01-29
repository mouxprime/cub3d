/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:57:15 by jmenard           #+#    #+#             */
/*   Updated: 2025/02/21 13:41:24 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clear_image(void)
{
	t_mlx	*mlx;
	int		x;
	int		y;
	char	*dst;

	mlx = get_mlx(NULL);
	y = 0;
	while (y < SCREEN_H)
	{
		x = 0;
		while (x < SCREEN_W)
		{
			dst = mlx->image->addr + (y * mlx->image->line_len + x
					* (mlx->image->bpp / 8));
			*(unsigned int *)dst = 0x000000;
			x++;
		}
		y++;
	}
}

void	draw_c_f(int x)
{
	t_mlx			*mlx;
	char			*dst;
	int				y;
	unsigned long	color;

	mlx = get_mlx(NULL);
	y = 0;
	color = mlx->image->color_c;
	while (y < SCREEN_H / 2)
	{
		dst = mlx->image->addr + (y * mlx->image->line_len + x
				* (mlx->image->bpp / 8));
		*(unsigned int *)dst = color;
		y++;
	}
	color = mlx->image->color_f;
	while (y < SCREEN_H)
	{
		dst = mlx->image->addr + (y * mlx->image->line_len + x
				* (mlx->image->bpp / 8));
		*(unsigned int *)dst = color;
		y++;
	}
}

void	set_pixel(double *ray_x, double *ray_y,
			double s_x, double s_y)
{
	t_mlx	*mlx_struct;
	t_image	*img;
	char	*dst;
	double	screen_x;
	double	screen_y;

	mlx_struct = get_mlx(NULL);
	img = mlx_struct->image;
	*ray_x += s_x * 0.1;
	*ray_y += s_y * 0.1;
	screen_x = (*ray_x) * mlx_struct->minimap_scale;
	screen_y = (*ray_y) * mlx_struct->minimap_scale;
	if (screen_x < 0 || screen_x >= SCREEN_W
		|| screen_y < 0 || screen_y >= SCREEN_H)
		return ;
	dst = img->addr + ((int)screen_y * img->line_len
			+ (int)screen_x * (img->bpp / 8));
	*(unsigned int *)dst = 0x00FF00;
}

void	angle_left(t_mlx *mlx_struct)
{
	mlx_struct->player->angle -= 0.02;
	if (mlx_struct->player->angle < 0)
		mlx_struct->player->angle += 2 * M_PI;
}

void	angle_right(t_mlx *mlx_struct)
{
	mlx_struct->player->angle += 0.02;
	if (mlx_struct->player->angle >= 2 * M_PI)
		mlx_struct->player->angle -= 2 * M_PI;
}

// void	print_struct(int type)
// {
// 	int		i;
// 	t_mlx	*mlx_struct;

// 	i = 0;
// 	mlx_struct = get_mlx(NULL);
// 	printf("---RAY---\n");
// 	printf("dir_x = %f\n", mlx_struct->ray->dir_x);
// 	printf("dir_y = %f\n", mlx_struct->ray->dir_y);
// 	printf("plan_x = %f\n", mlx_struct->ray->plan_x);
// 	printf("plan_y = %f\n", mlx_struct->ray->plan_y);
// 	printf("---PLAYER---\n");
// 	printf("player X = %f\n", mlx_struct->player->pos_x);
// 	printf("player Y = %f\n", mlx_struct->player->pos_y);
// 	printf("Angle = %f\n", mlx_struct->player->angle);
// 	printf("fov_rad = %f\n", mlx_struct->player->fov_rad);
// 	printf("---MAP---\n");
// 	if (type > 0)
// 	{
// 		while (mlx_struct->data->map2d[i])
// 		{
// 			printf("line[%d]=%s", i, mlx_struct->data->map2d[i]);
// 			i++;
// 		}
// 		printf("pos player X = %d\n", mlx_struct->data->map_pos_x);
// 		printf("pos player Y = %d\n", mlx_struct->data->map_pos_y);
// 	}
// 	printf("map width = %d\n", mlx_struct->data->map_width);
// 	printf("map height = %d\n", mlx_struct->data->map_height);
// }
