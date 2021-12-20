/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:10:25 by jaebae            #+#    #+#             */
/*   Updated: 2021/12/20 12:30:59 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	static	void	(*funcs[10])() = {p, c, d, s, x_up, u, NULL, d, x_lo, per};
	const char		*format_c = "pcdsXuix%";
	va_list			op;
	int				cnt;
	int				i;

	i = 0;
	cnt = 0;
	va_start(op, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (ft_strchr(format_c, format[++i]))
				funcs[format[i] % 14](op, &cnt);
			i++;
			continue ;
		}	
		write(1, &format[i++], 1);
		cnt++;
	}
	va_end(op);
	return (cnt);
}
