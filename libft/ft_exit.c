/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:44:13 by jmenard           #+#    #+#             */
/*   Updated: 2025/01/31 15:45:24 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mandatory/cub3d.h"

void	exit_now(int status)
{
	close_fds();
	ft_malloc(0, 0, 2, status);
}

void	clear_soft_data(void)
{
	ft_malloc(0, 0, 3, 0);
}

void	print_trash_list(void)
{
	ft_malloc(0, 0, 4, 0);
}

void	safe_exit(t_trash *trash, int exit_status)
{
	ft_lstclear(&trash, ft_del);
	exit(exit_status);
}

void	ft_del(void *content)
{
	free(content);
	content = NULL;
}
