/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:51:37 by jmenard           #+#    #+#             */
/*   Updated: 2025/02/24 14:34:03 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_4(char *file_name)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (false);
	line = find_map(fd);
	while (line && line[0] != '\n')
		line = get_next_line(fd);
	line = get_next_line(fd);
	if (line && line[0] != '\n')
		return (close(fd), false);
	return (close(fd), true);
}

char	*find_map(int fd)
{
	int		i;
	char	*str;

	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		i = 0;
		while (str[i])
		{
			if (str[i] == '1')
				return (str);
			if (str[i] != ' ' && str[i] != '0' && str[i] != '1')
				break ;
			i++;
		}
	}
	return (NULL);
}

bool	is_number(char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i])
	{
		if (nbr[i] != '\n' && nbr[i] != '\0')
		{
			if (ft_isdigit(nbr[i]) == 0)
				return (false);
		}
		i++;
	}
	return (true);
}

bool	is_rgb(char *line)
{
	int		i;
	char	**nbr;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (i == 0)
		return (false);
	nbr = ft_split(&line[i], ',');
	i = 0;
	while (nbr[i])
	{
		if (is_number(nbr[i]) == false)
			return (false);
		if (ft_atoi(nbr[i]) < 0 || ft_atoi(nbr[i]) > 255)
			return (false);
		i++;
	}
	if (i != 3)
		return (false);
	return (true);
}

bool	is_in_double(int a, int b, char *file_name)
{
	int		fd;
	int		i;
	int		count;
	char	*line;

	i = 0;
	count = 0;
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
		if (line[i] == a && line[i + 1] == b)
			count++;
		if (count > 1)
			return (close(fd), false);
		line = get_next_line(fd);
	}
	return (close(fd), true);
}
