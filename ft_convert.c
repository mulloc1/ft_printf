/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:07:29 by jaebae            #+#    #+#             */
/*   Updated: 2021/12/18 18:05:29 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	d(va_list op, int *cnt)
{
	size_t	i;
	char	*str;
	int		num;

	num = va_arg(op, int);
	str = ft_itoa(num);
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		(*cnt)++;
		i++;
	}
	free(str);
}

void	c(va_list op, int *cnt)
{
	ft_putchar_fd(va_arg(op, int), 1);
	(*cnt)++;
}

void	s(va_list op, int *cnt)
{
	char	*str;

	str = va_arg(op, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		(*cnt) += 6;
		return ;
	}
	(*cnt) += ft_strlen(str);
	ft_putstr_fd(str, 1);
}

void	per(va_list op, int *cnt)
{
	op++;
	ft_putchar_fd('%', 1);
	*cnt += 1;
}

void	u(va_list op, int *cnt)
{
	unsigned int	num;
	size_t			i;
	char			buf[12];
	int				temp;

	temp = *cnt;
	num = va_arg(op, int);
	i = 0;
	while (num > 0)
	{
		buf[i++] = num % 10 + 48;
		num /= 10;
	}
	while (--i + 1 >= 1)
	{
		ft_putchar_fd(buf[i], 1);
		(*cnt)++;
	}
	if (temp == *cnt)
		*cnt += write(1, "0", 1);
}
