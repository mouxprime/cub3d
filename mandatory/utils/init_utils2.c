/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:14:17 by mianni            #+#    #+#             */
/*   Updated: 2025/02/08 19:14:17 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_tex_path(char *prefix, char *file_name)
{
	char	**s;
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
			if (line[i] == prefix[0] && line[i + 1] == prefix[1])
			{
				s = ft_split(line, ' ');
				return (close(fd), ft_substr(s[1], 0, ft_strlen(s[1]) - 1, 0));
			}
		}
		line = get_next_line(fd);
	}
	return (close(fd), NULL);
}

int	convert_img(t_image *img)
{
	t_player	*player;

	player = get_mlx(NULL)->player;
	img->textures_data[NORTH] = mlx_get_data_addr(img->textures[NORTH],
			&img->bpp_tex, &img->line_len_tex, &img->endian_tex);
	img->textures_data[SOUTH] = mlx_get_data_addr(img->textures[SOUTH],
			&img->bpp_tex, &img->line_len_tex, &img->endian_tex);
	img->textures_data[EAST] = mlx_get_data_addr(img->textures[EAST],
			&img->bpp_tex, &img->line_len_tex, &img->endian_tex);
	img->textures_data[WEST] = mlx_get_data_addr(img->textures[WEST],
			&img->bpp_tex, &img->line_len_tex, &img->endian_tex);
	player->addr_sword = mlx_get_data_addr(player->img_sword,
			&player->bpp_sword, &player->line_len_sword, &player->endian_sword);
	player->addr_sword_bis = mlx_get_data_addr(player->img_sword_bis,
			&player->bpp_sword, &player->line_len_sword, &player->endian_sword);
	if (get_mlx(NULL)->data->doors_flag == 1)
		img->textures_data[DOOR_OPEN] = mlx_get_data_addr(img->textures
			[DOOR_OPEN], &img->bpp_tex, &img->line_len_tex, &img->endian_tex);
	if (!img->textures_data[NORTH] || !img->textures_data[SOUTH]
		|| !img->textures_data[EAST] || !img->textures_data[WEST]
		|| !img->textures_data[DOOR_OPEN]
		|| !player->addr_sword || !player->addr_sword_bis)
		return (1);
	return (0);
}
