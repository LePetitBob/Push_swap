/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best_sort_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:03:01 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/26 17:05:08 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_limit	ft_get_size(t_list *a, t_list *b)
{
	t_limit	limits;
	t_stack	*tmp;

	limits.sa = 0;
	limits.sb = 0;
	tmp = a->first;
	while (tmp)
	{
		limits.sa++;
		tmp = tmp->next;
	}
	tmp = b->first;
	while (tmp)
	{
		limits.sb++;
		tmp = tmp->next;
	}
	return (limits);
}

void	ft_application(t_list *a, t_list *b, t_count count)
{
	while (count.bestrr--)
		ft_rr(a, b);
	while (count.bestrrr--)
		ft_rrr(a, b);
	while (count.bestra--)
		ft_ra(a);
	while (count.bestrb--)
		ft_rb(b);
	while (count.bestrra--)
		ft_rra(a);
	while (count.bestrrb--)
		ft_rrb(b);
	ft_pa(a, b);
}

t_count	ft_totalcheck(t_count count)
{
	count.total += count.ra;
	count.total += count.rb;
	count.total += count.rra;
	count.total += count.rrb;
	count.total += count.rr;
	count.total += count.rrr;
	if (!count.besttotal)
	{
		count.besttotal = count.total;
		count = ft_best_count_assign(count);
	}
	if (count.total < count.besttotal)
	{
		count.besttotal = count.total;
		count = ft_best_count_assign(count);
	}
	return (count);
}

t_count	ft_best_count(t_count count, t_list *a, t_list *b)
{
	count.rb += count.index;
	count = ft_r_to_rr(count, a, b);
	count = ft_count_rrop(count);
	count = ft_totalcheck(count);
	return (count);
}
