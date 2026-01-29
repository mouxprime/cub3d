/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:43:14 by mianni            #+#    #+#             */
/*   Updated: 2024/11/10 19:43:52 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_lstadd_back_fd(t_trash_files **lst, t_trash_files *new)
{
	t_trash_files	*struc;

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

t_trash_files	*ft_lstnew_fd(int fd)
{
	t_trash_files	*list_content;

	list_content = malloc(1 * sizeof(struct trash_file));
	if (!list_content)
		return (NULL);
	list_content->fd = fd;
	list_content->next = NULL;
	return (list_content);
}

t_trash_files	*get_files_list(t_trash_files *trash_files, int i)
{
	static t_trash_files	*tr_files = NULL;

	if (i == 0)
		tr_files = NULL;
	else if (tr_files == NULL)
		tr_files = trash_files;
	return (tr_files);
}

int	ft_open(const char *filename, int flag, int pipe)
{
	t_trash_files	*trash_file;
	int				fd;

	fd = 0;
	trash_file = get_files_list(NULL, 1);
	if (pipe == -2)
		fd = open(filename, flag);
	else if (pipe >= 3)
		fd = pipe;
	if (fd == -1)
		return (fd);
	if (!trash_file)
	{
		ft_lstadd_back_fd(&trash_file, ft_lstnew_fd(fd));
		get_files_list(trash_file, 1);
	}
	else
		ft_lstadd_back_fd(&trash_file, ft_lstnew_fd(fd));
	return (fd);
}

void	close_fds(void)
{
	t_trash_files	*list;
	t_trash_files	*temp;

	list = NULL;
	list = get_files_list(list, 1);
	if (list)
	{
		while (list)
		{
			temp = list->next;
			close(list->fd);
			list->fd = 0;
			list->next = NULL;
			free(list);
			list = temp;
		}
		get_files_list(NULL, 0);
		list = NULL;
	}
}

// void	print_fd_list(void)
// {
// 	t_trash_files	*lst;

// 	lst = get_files_list(NULL, 1);
// 	printf("||||OPENED FILES LIST||||\n");
// 	printf("||||||||||||||||||||||||\n");
// 	while (lst)
// 	{
// 		printf("fd ; %d\n", lst->fd);
// 		lst = lst->next;
// 	}
// 	printf("||||||||||||||||||||||||\n");
// }
