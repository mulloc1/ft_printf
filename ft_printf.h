/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 10:15:15 by jaebae            #+#    #+#             */
/*   Updated: 2021/12/08 18:57:34 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	p(va_list op, int *num);
void	c(va_list op, int *num);
void	d(va_list op, int *num);
void	s(va_list op, int *num);
void	x_up(va_list op, int *num);
void	u(va_list op, int *num);
void	x_lo(va_list op, int *num);
void	per(va_list op, int *num);

#endif
