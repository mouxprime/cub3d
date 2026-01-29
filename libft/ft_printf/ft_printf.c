/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:16:31 by joseph            #+#    #+#             */
/*   Updated: 2024/06/26 11:45:15 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list argument, const char f)
{
	int	len;

	len = 0;
	if (f == 'c')
		len += ft_putchar(va_arg(argument, int));
	else if (f == 's')
		len += ft_putstr(va_arg(argument, char *));
	else if (f == 'p')
		len += ft_print_hex_ptr(va_arg(argument, unsigned long int), f);
	else if (f == 'i' || f == 'd')
		len += ft_putnbr_print_int(va_arg(argument, int), len);
	else if (f == 'u')
		len += ft_putnbr_print_unsigned(va_arg(argument, unsigned int), len);
	else if (f == 'x' || f == 'X')
		len += ft_print_hex_ptr(va_arg(argument, unsigned int), f);
	else if (f == '%')
		len += ft_putchar('%');
	else
	{
		len += ft_putchar('%');
		len += ft_putchar(f);
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len_printf;

	i = 0;
	len_printf = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			len_printf += ft_format(args, str[i + 1]);
			i++;
		}
		else
			len_printf += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len_printf);
}

// int	main(int ac, char **av)
// {
// 	int		nbr;
// 	char	*str;

// 	(void)ac;
// 	(void)av;
// 	str = " %c %%%9 %c %10 %c %?";
// 	nbr = ft_printf(str, '5', '1', '4');
// 	printf("\n ft ; %d \n", nbr);
// 	nbr = printf(str, '5', '1', '4');
// 	printf("\n rl ; %d \n", nbr);
// 	printf("\n ============================================ \n");
// 	str = " %c %u %d %s %%%x %X %p";
// 	nbr = ft_printf(str, '5', -10, 1, str, 5464, 4654, str);
// 	printf("\n ft ; %d \n", nbr);
// 	nbr = printf(str, '5', -10, 1, str, 5464, 4654, str);
// 	printf("\n rl ; %d \n", nbr);
// 	printf("\n ============================================ \n");
// 	str = " %?%% %";
// 	nbr = ft_printf(str, str);
// 	printf("\n ft ; %d \n", nbr);
// 	nbr = printf(str, str);
// 	printf("\n rl ; %d \n", nbr);
// 	return (0);
// }
