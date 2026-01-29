/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/02/08 19:05:22 by mianni            #+#    #+#             */
/*   Updated: 2025/02/08 19:05:22 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_door_number(char **map)
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
	if (doors > 1)
		return (false);
	return (true);
}

bool	foret_de_if(char *line, int i)
{
	if ((line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		|| (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		|| (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		|| (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		|| line[i] == 'F' || line[i] == 'C' || line[i] == '\n')
		return (true);
	return (false);
}

bool	check_5(char *file_name)
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
		if (foret_de_if(line, i))
			line = get_next_line(fd);
		else
			return (close(fd), false);
	}
	return (close(fd), true);
}
