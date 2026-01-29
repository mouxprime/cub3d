/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:05:13 by jmenard           #+#    #+#             */
/*   Updated: 2025/02/24 13:04:17 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**init_map(char *map_name)
{
	char	**map;
	char	*str;
	int		fd;
	int		fd1;
	int		count;

	count = 1;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	find_map(fd);
	while (get_next_line(fd))
		count++;
	close(fd);
	map = ft_malloc((count + 1), sizeof(char *), 0, 0);
	if (!map)
		return (NULL);
	fd1 = open(map_name, O_RDONLY);
	if (fd1 == -1)
		return (NULL);
	str = find_map(fd1);
	map[0] = str;
	if (!str)
		return (NULL);
	return (fill_map(map, fd1));
}

int	check_doors_position(char **map)
{
	int	i;
	int	j;
	int	doors;

	i = 0;
	doors = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'D')
				doors++;
			j++;
		}
		i++;
	}
	if (doors != 1 && doors != 0)
		return (error_parsing(6), 2);
	return (1);
}

bool	check_map(char **map)
{
	int	i;
	int	j;
	int	player_position;

	i = 0;
	player_position = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr(" 01\nNSWED", map[i][j]))
				return (false);
			if (ft_strchr("NSWE", map[i][j]))
				player_position++;
			j++;
		}
		i++;
	}
	if (player_position != 1)
		return (false);
	check_doors_position(map);
	return (true);
}

bool	check_map_border(char **map)
{
	size_t	i;
	size_t	j;
	size_t	max_i;
	size_t	max_j;

	i = 0;
	max_i = count_max_i(map);
	while (map[i])
	{
		j = 0;
		max_j = count_max_j(map[i]);
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (j == 0 || i == 0 || j >= max_j - 1 || i >= max_i - 1)
					return (false);
				if (check_around(map, i, j) == false)
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

char	**parse_it(char *map_name)
{
	char	**map;

	if (parse_ressources(map_name) == false)
		return (error_parsing(5), NULL);
	if (check_cub_extension(map_name) == false)
		return (NULL);
	map = init_map(map_name);
	if (!map)
		return (error_parsing(2), NULL);
	if (check_map(map) == false)
		return (error_parsing(3), NULL);
	if (check_map_border(map) == false)
		return (error_parsing(4), NULL);
	if (check_door_number(map) == false)
		return (error_parsing(6), NULL);
	return (map);
}
