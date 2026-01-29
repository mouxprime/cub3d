/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:51:08 by mianni            #+#    #+#             */
/*   Updated: 2025/02/24 11:52:21 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_cub_extension(char *str)
{
	int		i;
	char	*extension;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			break ;
		else
			i++;
	}
	if (!str[i])
		return (false);
	else
	{
		extension = ft_substr(str, i, ft_strlen(str) - i, 0);
		if (i == 0)
			return (error_parsing(1), false);
		else if (ft_strncmp(".cub\0", extension, 5) == 0)
			return (true);
		else
			return (error_parsing(1), false);
	}
}

int	count_max_i(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	count_max_j(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

bool	check_around_bis(char **m, int i, int j)
{
	if (m[i - 1][j - 1] != '1' && m[i - 1][j - 1] != '0'
		&& m[i - 1][j - 1] != 'N'
		&& m[i - 1][j - 1] != 'S' && m[i - 1][j - 1] != 'W'
		&& m[i - 1][j - 1] != 'E'
		&& m[i - 1][j - 1] != 'D')
		return (false);
	if (m[i - 1][j + 1] != '1' && m[i - 1][j + 1] != '0'
		&& m[i - 1][j + 1] != 'N'
		&& m[i - 1][j + 1] != 'S' && m[i - 1][j + 1] != 'W'
		&& m[i - 1][j + 1] != 'E'
		&& m[i - 1][j + 1] != 'D')
		return (false);
	if (m[i + 1][j - 1] != '1' && m[i + 1][j - 1] != '0'
		&& m[i + 1][j - 1] != 'N'
		&& m[i + 1][j - 1] != 'S' && m[i + 1][j - 1] != 'W'
		&& m[i + 1][j - 1] != 'E'
		&& m[i + 1][j - 1] != 'D')
		return (false);
	if (m[i + 1][j + 1] != '1' && m[i + 1][j + 1] != '0'
		&& m[i + 1][j + 1] != 'N'
		&& m[i + 1][j + 1] != 'S' && m[i + 1][j + 1] != 'W'
		&& m[i + 1][j + 1] != 'E'
		&& m[i + 1][j + 1] != 'D')
		return (false);
	return (true);
}

bool	check_around(char **map, int i, int j)
{
	if (map[i - 1][j] != '1' && map[i - 1][j] != '0' && map[i - 1][j] != 'N'
		&& map[i - 1][j] != 'S' && map[i - 1][j] != 'W' && map[i - 1][j] != 'E'
		&& map[i - 1][j] != 'D')
		return (false);
	if (map[i + 1][j] != '1' && map[i + 1][j] != '0' && map[i + 1][j] != 'N'
		&& map[i + 1][j] != 'S' && map[i + 1][j] != 'W' && map[i + 1][j] != 'E'
		&& map[i + 1][j] != 'D')
		return (false);
	if (map[i][j - 1] != '1' && map[i][j - 1] != '0' && map[i][j - 1] != 'N'
		&& map[i][j - 1] != 'S' && map[i][j - 1] != 'W' && map[i][j - 1] != 'E'
		&& map[i][j - 1] != 'D')
		return (false);
	if (map[i][j + 1] != '1' && map[i][j + 1] != '0' && map[i][j + 1] != 'N'
		&& map[i][j + 1] != 'S' && map[i][j + 1] != 'W' && map[i][j + 1] != 'E'
		&& map[i][j + 1] != 'D')
		return (false);
	if (check_around_bis(map, i, j) == false)
		return (false);
	return (true);
}
