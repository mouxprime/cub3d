/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minilibx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:16:15 by mianni            #+#    #+#             */
/*   Updated: 2025/02/24 13:21:35 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	destroy_window(t_mlx *mlx_struct)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (mlx_struct->image->textures[i])
			mlx_destroy_image(mlx_struct->mlx_p,
				mlx_struct->image->textures[i]);
		i++;
	}
	if (mlx_struct->image->img)
		mlx_destroy_image(mlx_struct->mlx_p, mlx_struct->image->img);
	if (mlx_struct->player->img_sword)
		mlx_destroy_image(mlx_struct->mlx_p, mlx_struct->player->img_sword);
	if (mlx_struct->player->img_sword_bis)
		mlx_destroy_image(mlx_struct->mlx_p, mlx_struct->player->img_sword_bis);
	if (mlx_struct->data->doors_flag != 0)
		mlx_destroy_image(mlx_struct->mlx_p,
			mlx_struct->image->textures[DOOR_OPEN]);
	destroy_mlx(mlx_struct);
	ft_malloc(0, 0, 2, 0);
	exit(0);
	return (0);
}

int	set_screen(void)
{
	t_mlx	*mlx_struct;

	mlx_struct = get_mlx(NULL);
	mlx_struct->fps++;
	clear_image();
	if (cast_ray() == -1)
		return (1);
	if (load_minimap() == -1)
		return (1);
	display_fps();
	sword_loop(mlx_struct);
	return (0);
}

int	handle_movement(t_mlx *mlx_struct)
{
	if (mlx_struct->keys.w || mlx_struct->keys.up)
		move_forward(mlx_struct);
	if (mlx_struct->keys.s || mlx_struct->keys.down)
		move_backward(mlx_struct);
	if (mlx_struct->keys.a)
		move_right(mlx_struct);
	if (mlx_struct->keys.d)
		move_left(mlx_struct);
	if (mlx_struct->keys.left)
		angle_left(mlx_struct);
	if (mlx_struct->keys.right)
		angle_right(mlx_struct);
	set_screen();
	return (0);
}

int	mouse_hook(int x, int y, void *param)
{
	static int	last_x = -1;
	t_mlx		*mlx_struct;
	double		sensitivity;

	(void)y;
	mlx_struct = (t_mlx *)param;
	sensitivity = 0.015;
	if (last_x != -1)
	{
		if (x > last_x)
			mlx_struct->player->angle += sensitivity * (x - last_x);
		else if (x < last_x)
			mlx_struct->player->angle -= sensitivity * (last_x - x);
	}
	if (mlx_struct->player->angle >= 2 * M_PI)
		mlx_struct->player->angle -= 2 * M_PI;
	else if (mlx_struct->player->angle < 0)
		mlx_struct->player->angle += 2 * M_PI;
	last_x = x;
	return (0);
}

void	init_minilibx(t_mlx *mlx_struct, char *file_name)
{
	mlx_struct->mlx_p = mlx_init();
	mlx_struct->mlx_win = mlx_new_window(mlx_struct->mlx_p, SCREEN_W, SCREEN_H,
			"cub3D");
	mlx_struct->image->img = mlx_new_image(mlx_struct->mlx_p, SCREEN_W,
			SCREEN_H);
	mlx_struct->image->addr = mlx_get_data_addr(mlx_struct->image->img,
			&mlx_struct->image->bpp, &mlx_struct->image->line_len,
			&mlx_struct->image->endian);
	mlx_hook(mlx_struct->mlx_win, DestroyNotify, StructureNotifyMask,
		destroy_window, mlx_struct);
	if (open_img(file_name, mlx_struct->image, mlx_struct->player) != 0)
	{
		printf("Error\n");
		printf("Some ressources are not loading\n");
		destroy_window(mlx_struct);
	}
	mlx_hook(mlx_struct->mlx_win, 2, 1L << 0, key_press, mlx_struct);
	mlx_hook(mlx_struct->mlx_win, 3, 1L << 1, key_release, mlx_struct);
	mlx_hook(mlx_struct->mlx_win, 6, 1L << 6, mouse_hook, mlx_struct);
	mlx_hook(mlx_struct->mlx_win, 4, (1L << 2), key_press_sword, mlx_struct);
	mlx_struct->fps = 0;
	mlx_loop_hook(mlx_struct->mlx_p, handle_movement, mlx_struct);
	mlx_loop(mlx_struct->mlx_p);
}
