/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:00:16 by jmenard           #+#    #+#             */
/*   Updated: 2025/02/07 17:17:07 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	wich_tex(t_ray *ray, t_mlx *mlx)
{
	if (ray->side == 0)
	{
		if (ray->ray_x > 0)
			ray->tex_index = EAST;
		else
			ray->tex_index = WEST;
		ray->wall_hit = mlx->player->pos_y + ray->perp_wall_dist * ray->ray_y;
	}
	else
	{
		if (ray->ray_y > 0)
			ray->tex_index = SOUTH;
		else
			ray->tex_index = NORTH;
		ray->wall_hit = mlx->player->pos_x + ray->perp_wall_dist * ray->ray_x;
	}
	if (mlx->data->map2d[ray->j_y][ray->j_x] == 'D')
		ray->tex_index = DOOR_OPEN;
}

void	draw_column_bis(t_mlx *mlx, int draw_end, int draw_start, int x)
{
	t_image	*img;
	t_ray	*ray;
	char	*dst;
	int		y;
	int		color;

	y = draw_start;
	img = mlx->image;
	ray = mlx->ray;
	while (y < draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & (img->tex_height - 1);
		ray->tex_pos += ray->step_tex;
		color = *(unsigned int *)(img->textures_data[ray->tex_index]
				+ (ray->tex_y * img->line_len_tex + ray->tex_x * (img->bpp_tex
						/ 8)));
		dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
		y++;
	}
}

void	draw_column(int x, int draw_start, int draw_end)
{
	t_mlx	*mlx;
	t_image	*img;
	t_ray	*ray;

	mlx = get_mlx(NULL);
	img = mlx->image;
	ray = mlx->ray;
	wich_tex(ray, mlx);
	ray->wall_hit -= floor(ray->wall_hit);
	ray->tex_x = (int)(ray->wall_hit * img->tex_width);
	if ((ray->side == 0 && ray->ray_x < 0) || (ray->side == 1
			&& ray->ray_y > 0))
		ray->tex_x = img->tex_width - ray->tex_x - 1;
	ray->step_tex = 1.0 * img->tex_height / ray->line_height;
	ray->tex_pos = (draw_start - SCREEN_H / 2 + ray->line_height / 2)
		* ray->step_tex;
	draw_column_bis(mlx, draw_end, draw_start, x);
}
