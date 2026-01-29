/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:14:26 by jmenard           #+#    #+#             */
/*   Updated: 2024/11/07 17:57:43 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_sub_len(char *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == charset)
			i++;
		while (str[i] && str[i] != charset)
		{
			if (str[i + 1] == '\0')
				return (count + 1);
			count++;
			i++;
		}
		if (str[i] == charset)
			break ;
		i++;
	}
	return (count);
}

int	ft_count_split(char *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == charset)
			i++;
		if (!str[i])
			break ;
		while (str[i] && str[i] != charset)
			i++;
		count++;
	}
	return (count);
}

char	*ft_split_strs(char *str, char charset)
{
	int		i;
	int		strlen;
	char	*sous_str;

	i = 0;
	strlen = ft_str_sub_len(str, charset);
	sous_str = ft_malloc((strlen + 1), sizeof(char), 0, 0);
	if (!sous_str)
		return (NULL);
	while (i < strlen)
	{
		sous_str[i] = str[i];
		i++;
	}
	sous_str[i] = '\0';
	return (sous_str);
}

char	**ft_split(char *str, char charset)
{
	char	**final_str;
	int		i;
	int		c;
	int		nbrwords;

	i = 0;
	c = 0;
	nbrwords = ft_count_split(str, charset);
	final_str = ft_malloc((nbrwords + 1), sizeof(char *), 0, 0);
	if (!final_str)
		return (NULL);
	while (c < nbrwords)
	{
		while (str[i] == charset)
			i++;
		final_str[c] = ft_split_strs(&str[i], charset);
		c++;
		i = i + ft_str_sub_len(&str[i], charset);
	}
	final_str[c] = NULL;
	return (final_str);
}
