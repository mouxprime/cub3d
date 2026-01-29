/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:29:48 by jmenard           #+#    #+#             */
/*   Updated: 2024/05/24 14:41:36 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_bis;
	char	*src_bis;

	i = 0;
	dest_bis = (char *)dest;
	src_bis = (char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		dest_bis[i] = src_bis[i];
		i++;
	}
	return (dest);
}
