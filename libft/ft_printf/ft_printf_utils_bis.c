/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:32:57 by joseph            #+#    #+#             */
/*   Updated: 2024/06/26 11:37:09 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

unsigned long int	ft_count_base(unsigned long int nbr, const char type)
{
	long int	compteur;

	compteur = 0;
	if (type == 'p')
		compteur += 2;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 16;
		compteur++;
	}
	return (compteur);
}

unsigned long int	ft_putnbr_base(unsigned long int nbr, const char type)
{
	unsigned long int	result;

	if (nbr / 16 != 0)
	{
		ft_putnbr_base(nbr / 16, type);
	}
	result = nbr % 16;
	if (result < 10)
		ft_putchar(result + '0');
	else
	{
		if (type == 'x' || type == 'p')
			ft_putchar((result - 10) + 'a');
		else if (type == 'X')
			ft_putchar((result - 10) + 'A');
	}
	return (result);
}

unsigned long int	ft_print_hex_ptr(unsigned long int nbr, const char type)
{
	if (type == 'p' && nbr != 0)
		write(1, "0x", 2);
	if (type == 'p' && nbr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (nbr == 0)
	{
		return (write(1, "0", 1));
	}
	else
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr *= -1;
		}
		ft_putnbr_base(nbr, type);
	}
	return (ft_count_base(nbr, type));
}
