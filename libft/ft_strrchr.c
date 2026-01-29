/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:46:14 by jmenard           #+#    #+#             */
/*   Updated: 2024/05/27 16:00:03 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				j;
	unsigned char	*bis_s;
	unsigned char	bis_c;

	j = 0;
	i = ft_strlen(s);
	bis_s = (unsigned char *)s;
	bis_c = (unsigned char)c;
	while (i >= j)
	{
		if (bis_s[i] == bis_c)
			return ((char *)&s[i]);
		i--;
	}
	if (bis_c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
