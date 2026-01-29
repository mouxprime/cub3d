/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:04:17 by jmenard           #+#    #+#             */
/*   Updated: 2024/05/29 14:48:15 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long int	i;
	const unsigned char	*t;
	unsigned char		d;

	i = 0;
	t = (const unsigned char *)s;
	d = (unsigned char)c;
	while (i != n)
	{
		if (t[i] == d)
			return ((void *)(&s[i]));
		i++;
	}
	return (NULL);
}
