/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:17:26 by joseph            #+#    #+#             */
/*   Updated: 2024/06/26 11:33:30 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr_print_int(int n, int len)
{
	if (n < -2147483647)
	{
		write(1, "-2147483648", 11);
		len = 11;
	}
	if (n <= -1 && n != -2147483648)
	{
		write(1, "-", 1);
		len++;
		n *= -1;
	}
	if (n >= 10 && n != -2147483648)
	{
		len += ft_putnbr_print_int((n / 10), 0);
		len += ft_putnbr_print_int((n % 10), 0);
	}
	if (n != -2147483648 && n <= 9)
	{
		len += ft_putchar(n + 48);
	}
	return (len);
}

int	ft_putnbr_print_unsigned(unsigned int n, unsigned int len1)
{
	if (n >= 10)
	{
		len1 += ft_putnbr_print_unsigned((n / 10), 0);
		len1 += ft_putnbr_print_unsigned((n % 10), 0);
	}
	else
		len1 += ft_putchar(n + 48);
	return (len1);
}
