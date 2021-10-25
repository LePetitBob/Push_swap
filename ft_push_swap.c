/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 03:42:18 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/24 18:49:32 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int val)
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
		if (((data.nbargs % 2 == 1) && data.diff == 0)
			|| ((data.nbargs % 2 == 0) && data.diff == 1))
			return (check->value);
		check = check->next;
	}
	return (0);
}

t_data	ft_find_limits(t_list *a, t_data data)
{
	t_stack	*tmp;

	data.highest = a->first->value;
	data.lowest = a->first->value;
	tmp = a->first;
	while (tmp)
	{
		if (tmp->value > data.highest)
			data.highest = tmp->value;
		if (tmp->value < data.lowest)
			data.lowest = tmp->value;
		tmp = tmp->next;
	}
	return (data);
}

int	ft_check_sorted(t_list *a)
{
	t_stack	*tmp;

	tmp = a->first;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_push_swap(t_list *a, t_list *b, t_data data)
{
	data.median = ft_find_median(a, data);
	data = ft_find_limits(a, data);
	if (ft_sortedbutwrongpos(a))
		ft_smart_shift(a, data.lowest);
	if (ft_check_sorted(a))
		return ;
	if (data.nbargs - 1 <= 5)
	{
		ft_perfect_sort(a, b, data);
		return ;
	}
	ft_best_push(a, b, data);
	if (ft_sortedbutwrongpos(a))
		ft_smart_shift(a, data.lowest);
}
