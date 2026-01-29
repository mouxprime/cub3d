/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:39:26 by jmenard           #+#    #+#             */
/*   Updated: 2024/05/29 14:50:08 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	unsigned long int	i;
	unsigned long int	len_dest;
	unsigned long int	len_src;

	i = 0;
	len_dest = (unsigned long int)ft_strlen((const char *)dest);
	len_src = (unsigned long int)ft_strlen(src);
	if (n == 0)
		return (len_src);
	while (i < n - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (n > 0)
		dest[i] = '\0';
	return (len_src);
}
