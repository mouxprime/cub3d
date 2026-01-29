/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:26:47 by jmenard           #+#    #+#             */
/*   Updated: 2024/05/29 14:49:03 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*bis_s;
	unsigned char	bis_c;

	i = 0;
	bis_s = (unsigned char *)s;
	bis_c = (unsigned char)c;
	while (bis_s[i])
	{
		if (bis_s[i] == bis_c)
			return ((char *)&s[i]);
		i++;
	}
	if (bis_c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
