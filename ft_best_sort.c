/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:58:31 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/26 17:04:59 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_good_to_pa(t_list *a, long val, t_stack *a1, t_stack *a2)
{
	t_limit	limits;

	limits = ft_find_limits3(a);
	if ((val > limits.higha && a1->value == limits.lowa)
		|| (val < a1->value && a1->value == limits.lowa))
		return (1);
	if (val < a1->value && val > a2->value
		&& (a1->value != limits.higha || a2->value != limits.lowa))
		return (1);
	return (0);
}

int	ft_count_to_pa(t_list *a, long val, t_stack *a1, t_stack *a2)
{
	t_limit	limits;

	limits = ft_find_limits3(a);
	if ((val > limits.higha && a1->value == limits.lowa)
		|| (val < a1->value && a1->value == limits.lowa))
		return (1);
	if ((val > a1->value && val < a2->value)
		&& (a1->value != limits.higha || a2->value != limits.lowa))
		return (1);
	return (0);
}

t_count	ft_best_count_assign(t_count count)
{
	count.bestra = count.ra;
	count.bestrb = count.rb;
	count.bestrra = count.rra;
	count.bestrrb = count.rrb;
	count.bestrr = count.rr;
	count.bestrrr = count.rrr;
	return (count);
}

int	ft_count_ra(t_list *a, long val, t_count count)
{
	t_stack	*tmp;

	tmp = a->first;
	count.ra = 0;
	if (ft_good_to_pa(a, val, a->first, a->last))
		return (0);
	while (tmp->next)
	{
		count.ra++;
		if (ft_count_to_pa(a, val, tmp, tmp->next))
			return (count.ra);
		tmp = tmp->next;
	}
	return (count.ra);
}

void	ft_best_sort(t_list *a, t_list *b)
{
	t_stack	*tmp;
	t_count	count;
	t_limit	limits;

	while (b->first)
	{
		limits = ft_find_limits3(b);
		count = ft_init_count();
		tmp = b->first;
		if (!ft_good_to_pa(a, b->first->value, a->first, a->last))
		{
			while (tmp)
			{
				if (count.index <= count.besttotal
					|| (limits.sa - count.index) <= count.besttotal)
				{
					count = ft_reset_count(a, tmp->value, count);
					count = ft_best_count(count, a, b);
				}
				tmp = tmp->next;
				count.index++;
			}
		}
		ft_application(a, b, count);
	}
}
