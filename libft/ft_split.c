/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:07:00 by jaebae            #+#    #+#             */
/*   Updated: 2021/11/24 10:10:50 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_string_cnt(char const *s, char c)
{
	size_t	i;
	size_t	flag;
	size_t	cnt;

	i = -1;
	flag = 0;
	cnt = 0;
	while (s[++i])
	{
		if (s[i] != c && flag == 0)
		{
			cnt++;
			flag = 1;
		}
		if (s[i] == c)
			flag = 0;
	}
	return (cnt);
}

static char	*ft_word_create(char const *s, char *sep)
{
	size_t		len;
	size_t		i;
	char		*result;

	len = 0;
	i = -1;
	while (!ft_strchr(sep, s[++i]))
		len++;
	result = ft_calloc(sizeof(char), len + 1);
	if (result == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		result[i] = s[i];
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t		string_cnt;
	size_t		i;
	size_t		j;
	char		**result;
	char		sep[2];

	if (s == NULL)
		return (NULL);
	string_cnt = ft_string_cnt(s, c);
	sep[0] = c;
	sep[1] = '\0';
	result = ft_calloc(sizeof(char *), string_cnt + 1);
	if (result == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < string_cnt)
	{
		while (ft_strchr(sep, s[j]))
			j++;
		result[i] = ft_word_create(s + j, sep);
		while (!ft_strchr(sep, s[j]))
			j++;
	}
	return (result);
}
