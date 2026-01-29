/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sword.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:47:23 by jmenard           #+#    #+#             */
/*   Updated: 2025/02/24 13:11:39 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	get_sword_color(t_player *player, int i, int j)
{
	char	*addr;

	if (player->attack_frame > 0)
		addr = player->addr_sword_bis;
	else
		addr = player->addr_sword;
	return (*(unsigned int *)(addr + (i * player->line_len_sword
			+ j * (player->bpp_sword / 8))));
}

static void	render_sword_texture(t_player *player, t_point base, t_point offset)
{
	int	i;
	int	j;
	int	color;
	int	scaled_i;
	int	scaled_j;

	i = 0;
	while (i < player->tex_sword_height)
	{
		j = 0;
		while (j < player->tex_sword_width)
		{
			color = get_sword_color(player, i, j);
			if (color != 0x000000)
			{
				scaled_i = i * 6 + offset.y;
				scaled_j = j * 6 + offset.x;
				draw_square(base.x + scaled_j, base.y + scaled_i, 6, color);
			}
			j++;
		}
		i++;
	}
}

void	render_sword(t_mlx *mlx, t_player *player)
{
	t_point	base;
	t_point	offset;
	int		x;
	int		y;

	(void)mlx;
	x = SCREEN_W / 2;
	y = SCREEN_H - 360;
	base.x = x;
	base.y = y;
	offset.x = 0;
	offset.y = 0;
	if (player->attack_frame > 0)
	{
		offset.x = player->attack_frame * 4;
		offset.y = -(player->attack_frame * 6);
	}
	render_sword_texture(player, base, offset);
}

int	sword_loop(t_mlx *mlx)
{
	render_sword(mlx, mlx->player);
	if (mlx->player->attack_frame > 0)
		mlx->player->attack_frame--;
	return (0);
}

int	key_press_sword(t_mlx *mlx)
{
	t_player	*player;

	(void)mlx;
	player = get_mlx(NULL)->player;
	player->attack_frame = 10;
	return (0);
}
