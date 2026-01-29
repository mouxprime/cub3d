/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:30:44 by jmenard           #+#    #+#             */
/*   Updated: 2025/02/24 13:23:15 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_fps(t_mlx *mlx)
{
	static struct timeval	last_time = {0, 0};
	struct timeval			current_time;
	long					elapsed_time;
	int						fps;

	gettimeofday(&current_time, NULL);
	elapsed_time = (current_time.tv_sec - last_time.tv_sec) * 1000
		+ (current_time.tv_usec - last_time.tv_usec) / 1000;
	if (elapsed_time >= 1000)
	{
		last_time = current_time;
		fps = mlx->fps;
		mlx->fps = 0;
		return (fps);
	}
	return (0);
}

void	display_fps(void)
{
	t_mlx		*mlx;
	static int	fps = 0;
	static int	last_fps = 0;

	mlx = get_mlx(NULL);
	fps = get_fps(mlx);
	if (fps > 0)
		last_fps = fps;
	mlx_string_put(mlx->mlx_p, mlx->mlx_win, SCREEN_W - 150, 15, 0xe11e19,
		"FPS = ");
	if (last_fps <= 0)
		mlx_string_put(mlx->mlx_p, mlx->mlx_win, SCREEN_W - 115, 15, 0xe11e19,
			"0");
	else
		mlx_string_put(mlx->mlx_p, mlx->mlx_win, SCREEN_W - 115, 15, 0xe11e19,
			ft_itoa(last_fps));
}

void	destroy_mlx(t_mlx *map)
{
	if (map->mlx_p && map->mlx_win)
		mlx_destroy_window(map->mlx_p, map->mlx_win);
	map->mlx_win = NULL;
	if (map->mlx_p)
		mlx_destroy_display(map->mlx_p);
	free(map->mlx_p);
}

char	**fill_map(char **map, int fd)
{
	int	i;

	i = 0;
	while (map[i])
	{
		i++;
		map[i] = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

bool	is_player(char **map, int i, int j)
{
	if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'S'
		|| map[i][j] == 'W')
		return (false);
	return (true);
}
