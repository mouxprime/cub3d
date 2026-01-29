/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ressources.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:47:36 by mianni            #+#    #+#             */
/*   Updated: 2025/02/24 14:31:18 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_3(char *file_name)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (false);
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
			return (close(fd), true);
		if (line[i] == 'C' || line[i] == 'F')
		{
			if (is_rgb(&line[i + 1]) == false)
				return (close(fd), false);
		}
		line = get_next_line(fd);
	}
	return (close(fd), true);
}

bool	check_2(char *file_name)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (false);
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
			return (close(fd), true);
		if (is_in_double(line[i], line[i + 1], file_name) == false
			&& line[i] != '\n')
			return (close(fd), false);
		line = get_next_line(fd);
	}
	return (close(fd), true);
}

bool	check_1(char *file_name)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (false);
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
			return (close(fd), true);
		if ((line[i] == 'N' && line[i + 1] == 'O') || (line[i] == 'S' && line[i
					+ 1] == 'O') || (line[i] == 'W' && line[i + 1] == 'E')
			|| (line[i] == 'E' && line[i + 1] == 'A') || line[i] == 'F'
			|| line[i] == 'C' || line[i] == '\n')
			line = get_next_line(fd);
		else
			return (close(fd), false);
	}
	return (close(fd), true);
}

bool	check_0(int fd)
{
	int		i;
	char	*line;
	int		textures_nb;

	i = 0;
	textures_nb = 0;
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		if ((line[i] == 'N' && line[i + 1] == 'O') || (line[i] == 'S' && line[i
					+ 1] == 'O'))
			textures_nb++;
		if ((line[i] == 'W' && line[i + 1] == 'E') || (line[i] == 'E' && line[i
					+ 1] == 'A'))
			textures_nb++;
		line = get_next_line(fd);
	}
	if (textures_nb == 4)
		return (close(fd), true);
	return (close(fd), false);
}

bool	parse_ressources(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (false);
	if (check_0(fd) == false)
		return (false);
	if (check_1(file_name) == false)
		return (false);
	if (check_2(file_name) == false)
		return (false);
	if (check_3(file_name) == false)
		return (false);
	if (check_4(file_name) == false)
		return (false);
	if (check_5(file_name) == false)
		return (false);
	if (check_6(file_name, 0) == false)
		return (false);
	return (true);
}
