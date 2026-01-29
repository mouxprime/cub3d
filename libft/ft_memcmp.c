/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:21:20 by jmenard           #+#    #+#             */
/*   Updated: 2024/05/29 14:48:24 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long int	i;
	const unsigned char	*s1_bis;
	const unsigned char	*s2_bis;

	i = 0;
	s1_bis = (const unsigned char *)s1;
	s2_bis = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	while (s1_bis[i] == s2_bis[i] && i < n - 1)
		i++;
	return (s1_bis[i] - s2_bis[i]);
}
