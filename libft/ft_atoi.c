/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:21:38 by jaebae            #+#    #+#             */
/*   Updated: 2021/11/30 12:26:19 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	cnt;
	char	sign;
	int		result;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	cnt = 0;
	result = 0;
	while (str[i + cnt] <= '9' && str[i + cnt] >= '0')
	{
		result *= 10;
		result += str[i + cnt] - '0';
		cnt++;
	}
	if (cnt >= 20 && sign > 0)
		return (-1);
	else if (cnt >= 20 && sign < 0)
		return (0);
	return (result * sign);
}
