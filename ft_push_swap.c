/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 03:42:18 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/09 08:31:52 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_abs(int val)
{
	if (val < 0)
		val = -val;
	return (val);
}

long	ft_find_median(t_list *a, t_data data)
{
	t_stack	*check;
	t_stack	*tmp;

	check = a->first;
	while (check)
	{
		data.highest = 0;
		data.lowest = 0;
		tmp = a->first;
		while (tmp)
		{
			if (tmp->value > check->value)
				data.highest++;
			if (tmp->value < check->value)
				data.lowest++;
			tmp = tmp->next;
		}
		data.diff = ft_abs(data.highest - data.lowest);
		if (((data.nbargs % 2 == 1) && data.highest == 0)
			|| ((data.nbargs % 2 == 0) && data.highest == 1))
			return (check->value);
		check = check->next;
	}
	return (0);
}

int	ft_check_sorted(t_list *a)
{
	t_stack	*tmp;

	tmp = a->first;
	while (tmp->next)
	{
		if (tmp->value < tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_push_swap(t_list *a, t_list *b, t_data data)
{
	if (ft_check_sorted(a) && !(b->first))
		return ;
	data.median = ft_find_median(a, data);
	if (data.nbargs <= 5)
	{
		ft_perfect_sort(a, b, data);
		return ;
	}
	ft_best_push(a, b, data);
	return ;
}
