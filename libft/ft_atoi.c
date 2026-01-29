/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:45:59 by jmenard           #+#    #+#             */
/*   Updated: 2025/01/24 14:20:55 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_white_space(const char *src)
{
	long int	i;

	i = 0;
	while ((src[i] >= 9 && src[i] <= 13) || src[i] == 32)
		i++;
	return (i);
}

long int	ft_atoi(const char *src)
{
	long int	i;
	long int	neg;
	long int	n;

	i = ft_white_space(src);
	neg = 1;
	n = 0;
	if (!(src[i] >= 48 && src[i] <= 57))
	{
		if (src[i] == '-' || src[i] == '+')
		{
			if (src[i] == '-')
				neg = -1;
			i++;
		}
		if (!(src[i] >= 48 && src[i] <= 57))
			return (0);
	}
	while (src[i] && src[i] >= 48 && src[i] <= 57)
	{
		n *= 10;
		n += src[i] - 48;
		i++;
	}
	return (n *= neg);
}
