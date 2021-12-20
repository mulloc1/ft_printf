/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:53:06 by jaebae            #+#    #+#             */
/*   Updated: 2021/12/09 11:40:50 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	hex_print_int(va_list op, char *base, int *cnt)
{
	unsigned int	num;
	size_t			i;
	char			result[12];
	int				temp;

	temp = *cnt;
	num = va_arg(op, int);
	i = 0;
	while (num > 0)
	{
		result[i++] = base[num % 16];
		num /= 16;
	}
	while (--i + 1 >= 1)
	{
		ft_putchar_fd(result[i], 1);
		(*cnt)++;
	}
	if (temp == *cnt)
		(*cnt) += write(1, "0", 1);
}

void	x_up(va_list op, int *cnt)
{
	char	*base;

	base = "0123456789ABCDEF";
	hex_print_int(op, base, cnt);
}

void	x_lo(va_list op, int *cnt)
{
	char	*base;

	base = "0123456789abcdef";
	hex_print_int(op, base, cnt);
}

void	hex_print_long(va_list op, char *base, int *cnt)
{
	unsigned long	num;
	size_t			i;
	char			result[12];
	int				temp;

	temp = *cnt;
	num = va_arg(op, long);
	i = 0;
	while (num > 0)
	{
		result[i++] = base[num % 16];
		num /= 16;
	}
	while (--i + 1 >= 1)
	{
		ft_putchar_fd(result[i], 1);
		(*cnt)++;
	}
	if (temp == *cnt)
		(*cnt) += write(1, "0", 1);
}

void	p(va_list op, int *cnt)
{
	char	*base;

	base = "0123456789abcdef";
	write(1, "0x", 2);
	(*cnt) += 2;
	hex_print_long(op, base, cnt);
}
