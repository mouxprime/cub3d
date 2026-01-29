/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:50:54 by jmenard           #+#    #+#             */
/*   Updated: 2024/10/31 14:12:01 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_find(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start])
	{
		if (ft_is_find(s1[start], set) == 0)
			start++;
		else
			break ;
	}
	while (end > start)
	{
		if (ft_is_find(s1[end - 1], set) == 0)
			end--;
		else
			break ;
	}
	return (ft_substr(s1, start, (end - start), 0));
}
