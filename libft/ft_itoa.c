/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:37:43 by jmenard           #+#    #+#             */
/*   Updated: 2025/02/24 11:57:53 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_reverse(char *str)
{
	int		strlen;
	int		i;
	char	c;

	i = 0;
	strlen = (int)ft_strlen((const char *)str);
	strlen--;
	while (i < strlen)
	{
		c = str[strlen];
		str[strlen] = str[i];
		str[i] = c;
		i++;
		strlen--;
	}
	return (str);
}

char	*ft_itoa_bis(int size_str, int n, char *str, int neg)
{
	int	i;

	i = 0;
	while (i < size_str)
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	if (neg == 1)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_domalloc(size_t n, char *nb)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)ft_malloc((n + 1), sizeof(char), 0, 0);
	if (!str)
		return (NULL);
	while (i < n)
	{
		str[i] = nb[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		size_str;
	int		i;
	int		neg;
	char	*str;

	neg = 0;
	i = 0;
	if (n <= -2147483647)
		return (ft_domalloc(11, "-2147483648"));
	if (n == 0)
		return (ft_domalloc(1, "0"));
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	size_str = ft_intlen(n);
	str = (char *)ft_malloc((size_str + neg + 1), sizeof(char), 0, 0);
	if (!str)
		return (NULL);
	str = ft_itoa_bis(size_str, n, str, neg);
	return (ft_reverse(str));
}
