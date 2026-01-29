/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 18:30:42 by mianni            #+#    #+#             */
/*   Updated: 2025/02/08 18:30:42 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_pixel2(double x, double y, int color)
{
	char	*dst;
	t_image	*img;

	img = get_mlx(NULL)->image;
	if (x < 0 || x >= SCREEN_W || y < 0 || y >= SCREEN_H)
		return ;
	dst = img->addr + ((int)y * img->line_len + (int)x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	calculate_minimap_scale(t_mlx *mlx)
{
	int		map_width;
	int		map_height;
	double	scale_x;
	double	scale_y;

	map_width = mlx->data->map_width;
	map_height = mlx->data->map_height;
	scale_x = (double)MINIMAP_MAX_SIZE / map_width;
	scale_y = (double)MINIMAP_MAX_SIZE / map_height;
	if (scale_x < scale_y)
		mlx->minimap_scale = scale_x;
	else
		mlx->minimap_scale = scale_y;
}
