/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best_sort_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:55:03 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/26 17:01:43 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_limit	ft_find_limits3(t_list *a)
{
	t_stack	*tmp;
	t_limit	limits;

	limits.higha = a->first->value;
	limits.lowa = a->first->value;
	tmp = a->first;
	while (tmp)
	{
		if (tmp->value > limits.higha)
			limits.higha = tmp->value;
		if (tmp->value < limits.lowa)
			limits.lowa = tmp->value;
		tmp = tmp->next;
	}
	return (limits = ft_limit_compare(limits));
}

t_count	ft_init_count(void)
{
	t_count	count;

	count.ra = 0;
	count.rb = 0;
	count.rr = 0;
	count.rra = 0;
	count.rrb = 0;
	count.rrr = 0;
	count.total = 0;
	count.bestra = 0;
	count.bestrb = 0;
	count.bestrr = 0;
	count.bestrra = 0;
	count.bestrrb = 0;
	count.bestrrr = 0;
	count.besttotal = 0;
	count.index = 0;
	return (count);
}

t_count	ft_reset_count(t_list *a, long val, t_count count)
{
	count.ra = ft_count_ra(a, val, count);
	count.rb = 0;
	count.rra = 0;
	count.rrb = 0;
	count.rr = 0;
	count.rrr = 0;
	count.total = 0;
	return (count);
}

t_count	ft_count_rrop(t_count count)
{
	while (count.ra && count.rb)
	{
		count.rr++;
		count.ra--;
		count.rb--;
	}
	while (count.rra && count.rrb)
	{
		count.rrr++;
		count.rra--;
		count.rrb--;
	}
	return (count);
}

t_count	ft_r_to_rr(t_count count, t_list *a, t_list *b)
{
	t_limit	limits;

	limits = ft_get_size(a, b);
	if ((limits.sa - count.ra) + 1 < count.ra)
	{
		count.rra = (limits.sa - count.ra);
		count.ra = 0;
	}
	if ((limits.sb - count.rb) + 1 < count.rb)
	{
		count.rrb = (limits.sb - count.rb);
		count.rb = 0;
	}
	return (count);
}
