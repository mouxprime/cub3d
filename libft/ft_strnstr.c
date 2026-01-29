/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:22:00 by jmenard           #+#    #+#             */
/*   Updated: 2024/05/29 14:50:44 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isfind(const char *big, const char *little, size_t len, size_t c)
{
	unsigned long int	i;

	i = 0;
	while (little[i] && i < c + len)
	{
		if (big[i] != little[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_little;
	size_t	len_big;

	i = 0;
	len_little = ft_strlen(little);
	len_big = ft_strlen(big);
	if (!little || len_little == 0)
		return ((char *)big);
	if (len_big == 0)
		return (NULL);
	if (len < len_little || little == 0)
		return (NULL);
	while (big[i] && i < len - len_little + 1)
	{
		if (big[i] == little[0])
		{
			if (ft_isfind(&big[i], little, len, i) == 1)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
