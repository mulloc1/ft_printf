/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:16:28 by jaebae            #+#    #+#             */
/*   Updated: 2021/11/30 12:38:43 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == NULL)
	{
		if (new == NULL)
			return ;
		else if (new != NULL)
			new->next = NULL;
	}
	else if (*lst != NULL && new != NULL)
		new->next = *lst;
	*lst = new;
}
