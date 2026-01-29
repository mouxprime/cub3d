/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ressources2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:31:43 by mianni            #+#    #+#             */
/*   Updated: 2025/02/24 14:33:21 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_color_path(char *line)
{
	int		i;

	if (!line || line[0] == '\0' || line[1] != ' ')
		return (false);
	i = 0;
	while (line[i])
	{
		if (line[i] == ',' && (i == 0 || !ft_isdigit(line[i - 1])))
			return (false);
		i++;
	}
	return (true);
}

bool	check_6(char *file_name, int i)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (false);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i = 0;
		if (line[0] == '\0')
			break ;
		while (line[i])
		{
			if (line[i] == 'C' || line[i] == 'F')
			{
				if (!check_color_path(line))
					return (close(fd), false);
			}
			i++;
		}
	}
	return (close(fd), true);
}
