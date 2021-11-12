/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_checkargs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:53:29 by vduriez           #+#    #+#             */
/*   Updated: 2021/11/12 12:12:42 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ditto(int ac, char **av)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (i < ac)
	{
		j = 1;
		k = 0;
		while (j < ac)
		{
			if (ft_atol(av[i]) == ft_atol(av[j]))
				k++;
			j++;
		}
		if (k > 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkint(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (ft_atol(av[i]) < -2147483648 || ft_atol(av[i]) > 2147483647
			|| ft_strlen(av[i]) > 10)
			return (0);
		i++;
	}
	if (ft_ditto(ac, av))
		return (0);
	return (1);
}

int	ft_checkerargs(int ac, char **av)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (i < ac)
	{
		j = 0;
		k = 0;
		while (av[i][k] == ' ')
			k++;
		while (av[i][j + k])
		{
			if (j == 0 && (av[i][j + k] != '+' && av[i][j + k] != '-'
				&& (av[i][j + k] < 48 || av[i][j + k] > 57)))
				return (0);
			if (j != 0 && (av[i][j + k] < 48 || av[i][j + k] > 57))
				return (0);
			j++;
		}
		i++;
	}
	if (!ft_checkint(ac, av))
		return (0);
	return (1);
}