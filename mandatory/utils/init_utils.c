/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:36:05 by jmenard           #+#    #+#             */
/*   Updated: 2025/02/21 14:20:42 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	rgb_to_hex(int *rgb_tab)
{
	int	result;
	int	r;
	int	g;
	int	b;

	r = rgb_tab[0];
	g = rgb_tab[1];
	b = rgb_tab[2];
	result = (r << 16) | (g << 8) | b;
	return (result);
}

int	convert_tex(t_image *img, char *file_name)
{
	char	*string;
	char	**color;
	int		rgb[3];

	string = get_tex_path_rgb("F ", file_name);
	color = ft_split(string, ',');
	rgb[0] = ft_atoi(color[0]);
	rgb[1] = ft_atoi(color[1]);
	rgb[2] = ft_atoi(color[2]);
	img->color_f = rgb_to_hex(rgb);
	string = get_tex_path_rgb("C ", file_name);
	color = ft_split(string, ',');
	rgb[0] = ft_atoi(color[0]);
	rgb[1] = ft_atoi(color[1]);
	rgb[2] = ft_atoi(color[2]);
	img->color_c = rgb_to_hex(rgb);
	return (0);
}

void	find_door_position(t_mlx *mlx_struct)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = mlx_struct->data->map2d;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'D')
				break ;
			j++;
		}
		if (map[i][j] == 'D')
			break ;
		i++;
	}
	mlx_struct->data->door_height = i;
	mlx_struct->data->door_width = j;
}

int	open_doors_img(t_mlx *mlx_struct)
{
	t_image	*img;

	if (mlx_struct->data->doors_flag == 0)
		return (mlx_struct->image->textures[DOOR_OPEN] = NULL, 0);
	img = get_mlx(NULL)->image;
	find_door_position(get_mlx(NULL));
	img->textures[DOOR_OPEN] = mlx_xpm_file_to_image(mlx_struct->mlx_p,
			"ressources/door.xpm", &img->tex_width, &img->tex_height);
	if (!img->textures[DOOR_OPEN])
		return (1);
	return (0);
}

int	open_img(char *file_name, t_image *img, t_player *player)
{
	img->textures[NORTH] = mlx_xpm_file_to_image(get_mlx(NULL)->mlx_p,
			get_tex_path("NO", file_name), &img->tex_width, &img->tex_height);
	img->textures[SOUTH] = mlx_xpm_file_to_image(get_mlx(NULL)->mlx_p,
			get_tex_path("SO", file_name), &img->tex_width, &img->tex_height);
	img->textures[EAST] = mlx_xpm_file_to_image(get_mlx(NULL)->mlx_p,
			get_tex_path("EA", file_name), &img->tex_width, &img->tex_height);
	img->textures[WEST] = mlx_xpm_file_to_image(get_mlx(NULL)->mlx_p,
			get_tex_path("WE", file_name), &img->tex_width, &img->tex_height);
	player->img_sword = mlx_xpm_file_to_image(get_mlx(NULL)->mlx_p,
			"ressources/sword.xpm", &player->tex_sword_width,
			&player->tex_sword_height);
	player->img_sword_bis = mlx_xpm_file_to_image(get_mlx(NULL)->mlx_p,
			"ressources/sword_bis.xpm", &player->tex_sword_width,
			&player->tex_sword_height);
	if (open_doors_img(get_mlx(NULL)) == 1)
		if (!img->textures[DOOR_OPEN])
			return (1);
	if (!img->textures[NORTH] || !img->textures[SOUTH] || !img->textures[EAST]
		|| !img->textures[WEST] || !player->img_sword || !player->img_sword_bis)
		return (1);
	if (convert_img(img) == 1)
		return (1);
	if (convert_tex(img, file_name) == 1)
		return (1);
	return (0);
}
