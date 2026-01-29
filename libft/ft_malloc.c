/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:59:13 by jmenard           #+#    #+#             */
/*   Updated: 2025/02/04 16:23:52 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_trashlst(t_trash **list, int type)
{
	t_trash	*lst;

	lst = *list;
	if (type == 0)
		printf("trash_collector\n");
	if (type == 1)
		printf("env\n");
	printf("|||||||||||||||||\n");
	while (lst)
	{
		printf("pointer %p\n", lst->alloc);
		printf("lock ? %d\n", lst->lock);
		lst = lst->next;
	}
	printf("|||||||||||||||||\n");
}

t_trash	*chill_exit(t_trash *trash)
{
	ft_lstclear(&trash, ft_del);
	return (NULL);
}

void	*ft_malloc(size_t nmemb, size_t size, int lock, int exit_status)
{
	void			*str;
	static t_trash	*trash = NULL;

	if (lock == 2)
		safe_exit(trash, exit_status);
	str = malloc(nmemb * size);
	if (!str)
		safe_exit(trash, exit_status);
	if (lock == 0)
		ft_lstadd_front(&trash, ft_lstnew(str, lock));
	return ((void *)(str));
}
