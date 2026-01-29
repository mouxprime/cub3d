/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:54:53 by mianni            #+#    #+#             */
/*   Updated: 2025/02/06 16:47:49 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx_struct;
	char	**map;

	if (argc == 2)
	{
		map = parse_it(argv[1]);
		if (!map)
			return (ft_malloc(0, 0, 2, 0), 0);
		else
		{
			mlx_struct = init_struct();
			fill_struct(map, &mlx_struct);
			get_mlx(&mlx_struct);
		}
	}
	else
		return (error_parsing(0), 0);
	init_minilibx(&mlx_struct, argv[1]);
	ft_malloc(0, 0, 2, 0);
	return (1);
}
