/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:17:00 by joseph            #+#    #+#             */
/*   Updated: 2024/06/26 11:43:15 by jmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF H

# include<unistd.h>
# include<fcntl.h>
# include<stdlib.h>
# include<stdio.h>
# include<string.h>
# include<stdarg.h>
# include<limits.h>

int					ft_printf(const char *str, ...);
int					ft_format(va_list argument, const char f);
int					ft_putstr(char *str);
int					ft_putnbr_print_int(int n, int len);
int					ft_putnbr_print_unsigned(unsigned int n, unsigned int len1);
int					ft_putchar(char c);
unsigned long int	ft_count_base(unsigned long int nbr, const char type);
unsigned long int	ft_putnbr_base(unsigned long int nbr, const char type);
unsigned long int	ft_print_hex_ptr(unsigned long int nbr, const char type);

#endif