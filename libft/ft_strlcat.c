/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:17:47 by jmenard           #+#    #+#             */
/*   Updated: 2024/05/27 15:48:24 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	unsigned long int	i;
	unsigned long int	len_dest;
	unsigned long int	len_src;

	i = 0;
	len_dest = (unsigned long int)ft_strlen((const char *)dest);
	len_src = (unsigned long int)ft_strlen(src);
	if (len_dest >= n)
		return (n + len_src);
	while (i < n - len_dest - 1 && src[i])
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return ((size_t)len_dest + len_src);
}
