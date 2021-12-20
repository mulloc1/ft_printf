/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:34:37 by jaebae            #+#    #+#             */
/*   Updated: 2021/11/24 10:10:06 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	signed char	buf[12];
	signed char	temp;
	size_t		i;
	long		result;

	result = n;
	i = 0;
	temp = 0;
	if (result < 0)
	{
		temp = '-';
		result *= -1;
	}
	if (result == 0)
		buf[i++] = '0';
	while (result > 0)
	{
		buf[i++] = result % 10 + 48;
		result /= 10;
	}
	if (temp == '-')
		buf[i++] = temp;
	buf[i] = '\0';
	while (UINT_MAX - (--i) - 1 < UINT_MAX)
		write(fd, &buf[i], 1);
}
