/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perfect_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:51:10 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/13 04:13:35 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_limit	ft_limit_compare(t_limit limits)
{
	if (limits.higha > limits.highb)
		limits.highest = limits.higha;
	else
		limits.highest = limits.highb;
	if (limits.lowa < limits.lowb)
		limits.lowest = limits.lowa;
	else
		limits.lowest = limits.lowb;
	return (limits);
}

t_limit	ft_find_limits2(t_list *a, t_list *b, t_limit limits)
{
	t_stack	*tmp;

	limits.higha = a->first->value;
	limits.lowa = a->first->value;
	limits.highb = b->first->value;
	limits.lowb = b->first->value;
	tmp = a->first;
	while (tmp)
	{
		if (tmp->value > limits.higha)
			limits.higha = tmp->value;
		if (tmp->value < limits.lowa)
			limits.lowa = tmp->value;
		tmp = tmp->next;
	}
	tmp = b->first;
	while (tmp)
	{
		if (tmp->value > limits.highb)
			limits.highb = tmp->value;
		if (tmp->value < limits.lowb)
			limits.lowb = tmp->value;
		tmp = tmp->next;
	}
	return (limits = ft_limit_compare(limits));
}

void	ft_insert_sort(t_list *a, t_list *b, t_data data)
{
	t_limit	limits;

	(void)data;
	while (b->first)
	{
		limits = ft_find_limits2(a, b, limits);
		if ((b->first->value > limits.higha
				&& a->first->value == limits.lowa)
			|| (b->first->value < a->first->value
				&& a->first->value == limits.lowa)
			|| (b->first->value < a->first->value
				&& b->first->value > a->last->value))
			ft_pa(a, b);
		else
			ft_ra(a);
			//ft_smart_rotate(a, b, data);
	}
	if (!ft_check_sorted(a))
		ft_smart_shift(a, limits.lowest);
}

void	ft_perfect_sort(t_list *a, t_list *b, t_data data)
{
	if (data.nbargs == 2)
	{
		ft_sa(a);
		return ;
	}
	if (data.nbargs == 3)
	{
		ft_sort3(a);
		return ;
	}
	ft_sort5(a, b, data);
}
