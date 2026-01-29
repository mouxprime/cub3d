/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:30:41 by mianni            #+#    #+#             */
/*   Updated: 2025/02/08 20:52:03 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_mlx	init_struct(void)
{
	t_mlx	mlx_struct;

	mlx_struct.data = (t_data *)ft_malloc(1, sizeof(t_data), 0, 0);
	mlx_struct.player = (t_player *)ft_malloc(1, sizeof(t_player), 0, 0);
	mlx_struct.ray = (t_ray *)ft_malloc(1, sizeof(t_ray), 0, 0);
	mlx_struct.image = (t_image *)ft_malloc(1, sizeof(t_image), 0, 0);
	if (!mlx_struct.data || !mlx_struct.player)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	ft_bzero(mlx_struct.data, sizeof(t_data));
	ft_bzero(mlx_struct.player, sizeof(t_player));
	ft_bzero(mlx_struct.ray, sizeof(t_ray));
	ft_bzero(mlx_struct.image, sizeof(t_image));
	ft_bzero(&mlx_struct.keys, sizeof(t_keys));
	mlx_struct.speed = 0.055;
	return (mlx_struct);
}

double	put_player_angle(int letter)
{
	if (letter == 78)
		return (3 * M_PI / 2);
	if (letter == 83)
		return (M_PI / 2);
	if (letter == 87)
		return (M_PI);
	if (letter == 69)
		return (0);
	return (-1);
}

void	find_player_position(t_mlx *mlx_struct, char **map)
{
	int	i;
	int	j;

	i = 0;
	(void)map;
	while (mlx_struct->data->map2d[i])
	{
		j = 0;
		while (mlx_struct->data->map2d[i][j])
		{
			if (!is_player(mlx_struct->data->map2d, i, j))
				break ;
			else
				j++;
		}
		if (!is_player(mlx_struct->data->map2d, i, j))
			break ;
		else
			i++;
	}
	mlx_struct->player->fov_rad = (FOV * M_PI / 180);
	mlx_struct->player->pos_x = j;
	mlx_struct->player->pos_y = i;
	mlx_struct->player->angle = put_player_angle(mlx_struct->data->map2d[i][j]);
	mlx_struct->data->map2d[i][j] = '0';
}

void	fill_struct(char **map, t_mlx *mlx_struct)
{
	t_data	*data;
	size_t	line_max;

	line_max = 0;
	data = mlx_struct->data;
	data->map2d = map;
	data->map_height = 0;
	data->map_width = 0;
	if (data->map2d[0])
	{
		while (map[data->map_height])
		{
			if (ft_strlen(data->map2d[data->map_height]) > line_max)
				line_max = ft_strlen(data->map2d[data->map_height]);
			data->map_height++;
		}
		data->map_width = line_max;
	}
	find_player_position(mlx_struct, map);
	if (check_doors_position(map) == 1)
		mlx_struct->data->doors_flag = 1;
	else
		mlx_struct->data->doors_flag = 0;
}

t_mlx	*get_mlx(t_mlx *mlx_struct)
{
	static t_mlx	*mlx;

	if (!mlx && mlx_struct)
		mlx = mlx_struct;
	return (mlx);
}
