/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:23:17 by jmenard           #+#    #+#             */
/*   Updated: 2025/02/21 11:56:06 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_mlx *mlx_struct)
{
	double	angle;
	double	new_x;
	double	new_y;

	angle = get_view_angle(mlx_struct);
	new_x = mlx_struct->player->pos_x + cos(angle) * mlx_struct->speed;
	new_y = mlx_struct->player->pos_y + sin(angle) * mlx_struct->speed;
	if (is_walkable(mlx_struct->data->map2d, new_x, new_y))
	{
		mlx_struct->player->pos_x = new_x;
		mlx_struct->player->pos_y = new_y;
	}
}

void	move_backward(t_mlx *mlx_struct)
{
	double	angle;
	double	new_x;
	double	new_y;

	angle = get_view_angle(mlx_struct);
	new_x = mlx_struct->player->pos_x - cos(angle) * mlx_struct->speed;
	new_y = mlx_struct->player->pos_y - sin(angle) * mlx_struct->speed;
	if (is_walkable(mlx_struct->data->map2d, new_x, new_y))
	{
		mlx_struct->player->pos_x = new_x;
		mlx_struct->player->pos_y = new_y;
	}
}

void	move_right(t_mlx *mlx_struct)
{
	double	angle;
	double	new_x;
	double	new_y;

	angle = get_view_angle(mlx_struct) - M_PI_2;
	new_x = mlx_struct->player->pos_x + cos(angle) * mlx_struct->speed;
	new_y = mlx_struct->player->pos_y + sin(angle) * mlx_struct->speed;
	if (is_walkable(mlx_struct->data->map2d, new_x, new_y))
	{
		mlx_struct->player->pos_x = new_x;
		mlx_struct->player->pos_y = new_y;
	}
}

void	move_left(t_mlx *mlx_struct)
{
	double	angle;
	double	new_x;
	double	new_y;

	angle = get_view_angle(mlx_struct) + M_PI_2;
	new_x = mlx_struct->player->pos_x + cos(angle) * mlx_struct->speed;
	new_y = mlx_struct->player->pos_y + sin(angle) * mlx_struct->speed;
	if (is_walkable(mlx_struct->data->map2d, new_x, new_y))
	{
		mlx_struct->player->pos_x = new_x;
		mlx_struct->player->pos_y = new_y;
	}
}

char	*get_tex_path_rgb(char *prefix, char *file_name)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (false);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), NULL);
	while (line)
	{
		i = -1;
		while (line[++i])
		{
			if (line[i] != ' ')
			{
				if (line[i] == prefix[0] && line[i + 1] == prefix[1])
					return (close(fd), ft_substr(&line[i + 2], 0,
							ft_strlen(&line[i + 2]) - 1, 0));
			}
		}
		line = get_next_line(fd);
	}
	return (close(fd), NULL);
}
