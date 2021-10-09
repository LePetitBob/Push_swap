/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 02:59:11 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/06 03:40:15 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strchar(char c, char s)
{
	if (c == s)
		return (1);
	return (-1);
}

int	ft_size_w(const char *str, int i, char c)
{
	int	j;

	j = 0;
	while (ft_strchar(str[i], c) && str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

int	ft_count_word(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		if (ft_strchar(str[i], c) != -1)
			i++;
		else
		{
			count++;
			while (ft_strchar(str[i], c) == -1 && str[i] != 0)
			{
				i++;
			}
		}
	}
	return (count);
}

char	**ft_split(char const *str, char c, t_data data)
{
	char	**tab;

	if (!str)
		return (NULL);
	data.sk = 0;
	data.si = 0;
	tab = malloc(sizeof(char *) * (ft_count_word(str, c) + 1));
	if (!tab)
		return (0);
	while (data.si < ft_count_word(str, c) && str[0] != 0)
	{
		data.sj = 0;
		while (ft_strchar(str[data.sk], c) != -1 && str[data.sk] != 0)
			data.sk++;
		tab[data.si] = malloc(sizeof(char) * (ft_size_w(str, data.sk, c) + 1));
		if (!tab)
			return (0);
		while (ft_strchar(str[data.sk], c) == -1 && str[data.sk] != 0)
			tab[data.si][data.sj++] = str[data.sk++];
		tab[data.si][data.sj] = '\0';
		data.si++;
	}
	tab[data.si] = 0;
	return (tab);
}
