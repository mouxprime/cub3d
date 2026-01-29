/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mianni <mianni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:08:07 by jmenard           #+#    #+#             */
/*   Updated: 2025/02/07 17:17:58 by mianni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error_parsing(int type)
{
	ft_putstr_fd("Error\n", 2);
	if (type == 0)
		ft_putstr_fd("Wrong number of args, only one arg is accepted\n", 2);
	if (type == 1)
		ft_putstr_fd("Wrong format of file, only 'something'.cub is accepted\n",
			2);
	if (type == 2)
		ft_putstr_fd("No map in the file\n", 2);
	if (type == 3)
		ft_putstr_fd("Incorrect caracters in map / Wrong number of players\n",
			2);
	if (type == 4)
		ft_putstr_fd("Map is not close\n", 2);
	if (type == 5)
		ft_putstr_fd("Some ressources are not loadable\n", 2);
	if (type == 6)
		ft_putstr_fd("Only one door is accepted\n", 2);
}
