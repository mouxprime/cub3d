/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:15:49 by jmenard           #+#    #+#             */
/*   Updated: 2025/02/08 19:39:20 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	isline(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	isline_bis(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		if (buffer[i + 1] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

char	*line_read(int fd, char *buffer)
{
	char	*buffer_temp;
	char	*buffer_bis;
	int		read_len;

	read_len = 2;
	buffer_temp = ft_malloc(BUFFER_SIZE + 1, sizeof(char), 0, 0);
	if (!buffer_temp)
		return (NULL);
	if (!buffer)
		buffer = do_malloc(buffer);
	if (!buffer)
		return (NULL);
	while (read_len > 0)
	{
		read_len = read(fd, buffer_temp, BUFFER_SIZE);
		if (read_len == -1)
			return (NULL);
		buffer_temp[read_len] = '\0';
		buffer_bis = buffer;
		buffer = ft_strjoin_gnl(buffer_bis, buffer_temp);
		if (isline(buffer_temp) >= 0 || read_len <= 0 || !buffer)
			break ;
	}
	return (buffer);
}

char	*do_malloc(char *buf)
{
	buf = ft_malloc(1, sizeof(char), 0, 0);
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf[1024];
	char		*ret;
	char		*bis;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (buf[fd] = NULL);
	bis = line_read(fd, buf[fd]);
	if (!bis)
		return (NULL);
	ret = ft_substr_bis(bis, 0, isline_bis(bis) + 1);
	if (!ret)
		return (buf[fd] = NULL);
	buf[fd] = ft_substr_bis(bis, ft_strle(ret), ft_strle(bis) - ft_strle(ret));
	if (!buf[fd])
		return (buf[fd] = NULL);
	if (ret[0] == '\0')
		return (buf[fd] = NULL);
	return (ret);
}
