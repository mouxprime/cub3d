/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:14:14 by jmenard           #+#    #+#             */
/*   Updated: 2025/02/04 15:59:09 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_trash	*ft_lstnew(void *content, int lock)
{
	t_trash	*list_content;

	list_content = malloc(sizeof(struct trash_collector));
	if (!list_content)
		return (NULL);
	list_content->alloc = content;
	list_content->lock = lock;
	list_content->next = NULL;
	return (list_content);
}
