/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:30:16 by jaebae            #+#    #+#             */
/*   Updated: 2021/12/22 09:48:26 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	i += ft_putstr_fd(s, fd);
	i += ft_putchar_fd('\n', fd);
	return (i);
}
