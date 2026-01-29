/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:40:47 by jmenard           #+#    #+#             */
/*   Updated: 2024/11/02 14:11:55 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*struc;

	struc = *lst;
	if (struc == NULL)
		*lst = new;
	else
	{
		while (struc->next)
			struc = struc->next;
		struc->next = new;
	}
}
