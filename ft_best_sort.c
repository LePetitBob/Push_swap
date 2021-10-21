/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:58:31 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/21 21:46:49 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_count	ft_initcount(void)
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
	return (count);
}

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

int	ft_good_to_pa(t_list *a, long val, long vala1, long vala2)
{
	t_limit	limits;

	limits = ft_find_limits3(a);
	if ((val > limits.higha
			&& vala1 == limits.lowa)
		|| (val < vala1
			&& vala1 == limits.lowa)
		|| (val < vala1
			&& val > vala2))
		return (1);
	return (0);
}

t_count	ft_count_rrop(t_count count)
{
	if (count.ra > count.rb)
	{
		count.rr = count.ra - count.rb;
		count.ra -= count.rr;
		count.rb -= count.rr;
	}
	if (count.ra < count.rb)
	{
		count.rr = ft_abs(count.rb - count.ra);
		count.ra -= count.rr;
		count.rb -= count.rr;
	}
	if (count.rra > count.rrb)
	{
		count.rrr = count.rra - count.rrb;
		count.rra -= count.rrr;
		count.rrb -= count.rrr;
	}
	if (count.rra < count.rrb)
	{
		count.rrr = count.rrb - count.rra;
		count.rra -= count.rrr;
		count.rrb -= count.rrr;
	}
	return (count);
}

t_count	ft_best_count_assign(t_count count)
{
	printf("count.ra  = %d\n", count.ra);
	printf("count.rb  = %d\n", count.rb);
	printf("count.rra = %d\n", count.rra);
	printf("count.rrb = %d\n", count.rrb);
	printf("count.rr  = %d\n", count.rr);
	printf("count.rrr = %d\n", count.rrr);
	if (count.ra && (count.ra < count.rra))
	{
		count.bestra = count.ra;
		count.bestrra = 0;
		count.ra = 0;
	}
	if (count.rb && (count.rb < count.rrb))
	{
		count.bestrb = count.rb;
		count.bestrrb = 0;
		count.rb = 0;
	}
	if (count.rra && (count.rra < count.ra))
	{
		count.bestrra = count.rra;
		count.bestra = 0;
		count.rra = 0;
	}
	if (count.rrb && (count.rrb < count.rb))
	{
		count.bestrrb = count.rrb;
		count.bestrb = 0;
		count.rrb = 0;
	}
	if (count.rrr && (count.rrr < count.rr))
	{
		count.bestrrr = count.rrr;
		count.bestrr = 0;
		count.rrr = 0;
	}
	if (count.rr && (count.rr < count.rrr))
	{
		count.bestrr = count.rr;
		count.bestrrr = 0;
		count.rr = 0;
	}
	printf("		AND THEN		\n");
	printf("count.ra  = %d\n", count.ra);
	printf("count.rb  = %d\n", count.rb);
	printf("count.rra = %d\n", count.rra);
	printf("count.rrb = %d\n", count.rrb);
	printf("count.rr  = %d\n", count.rr);
	printf("count.rrr = %d\n", count.rrr);
	return (count);
}

int	ft_count_ra(t_list *a, long val, t_count count)
{
	t_stack	*tmp;

	tmp = a->first;
	if (ft_good_to_pa(a, val, a->first->value, a->last->value))
		return (0);
	while (tmp->next && !ft_good_to_pa(a, val, tmp->value, tmp->next->value))
	{
		count.ra++;
		tmp = tmp->next;
	}
	return (count.ra);
}

void	ft_application(t_list *a, t_list *b, t_count count)
{
	while(count.bestrr)
	{
		ft_rr(a, b);
		count.bestrr--;
	}
	while(count.bestrrr)
	{
		ft_rrr(a, b);
		count.bestrrr--;
	}
	while(count.bestra)
	{
		ft_ra(a);
		count.bestra--;
	}
	while(count.bestrb)
	{
		ft_rb(b);
		count.bestrb--;
	}
	while(count.bestrra)
	{
		ft_rra(a);
		count.bestrra--;
	}
	while(count.bestrrb)
	{
		ft_rrb(b);
		count.bestrrb--;
	}
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
	printf("						total = %d\n", count.total);
	if (!count.besttotal)
		count.besttotal = count.total;
	if (count.total < count.besttotal)
		count.besttotal = count.total;
	printf("						best total = %d\n", count.besttotal);
	return (count);
}

t_count	ft_reset_count(t_count count)
{
	count.ra = 0;
	count.rb = 0;
	count.rra = 0;
	count.rrb = 0;
	count.rr = 0;
	count.rrr = 0;
	count.total = 0;
	return (count);
}

t_limit	ft_get_size(t_list *a, t_list *b)
{
	t_limit	limits;
	t_stack	*tmp;

	limits.sizea = 0;
	limits.sizeb = 0;
	tmp = a->first;
	while (tmp)
	{
		limits.sizea++;
		tmp = tmp->next;
	}
	tmp = b->first;
	while (tmp)
	{
		limits.sizeb++;
		tmp = tmp->next;
	}
	return (limits);
}

t_count	ft_r_to_rr(t_count count, t_list *a, t_list *b)
{
	t_limit limits;

	limits = ft_get_size(a, b);
	if((limits.sizea - count.ra + 1) < count.ra)
	{
		count.rra = limits.sizea - count.ra + 1;
		count.ra = 0;
	}
	return (count);
	if((limits.sizeb - count.rb + 1) < count.rb)
	{
		count.rrb = limits.sizeb - count.rb + 1;
		count.rb = 0;
	}
	return (count);
}

void	ft_best_sort(t_list *a, t_list *b)
{
	t_stack	*tmp;
	t_count	count;
	int		adjust;

	while (b->first)
	{
		adjust = 0;
		count = ft_initcount();
		tmp = b->first;
		while (tmp)
		{
		printf("					 		adjust : %d\n\n", adjust);
			count = ft_reset_count(count);
			count.ra = ft_count_ra(a, tmp->value, count);
			count.rb += adjust;
	printf("			count.rb  = %d\n", count.rb);
			count = ft_r_to_rr(count, a, b);
		// printf("KUKUKUKUKUKUKUKUKUKU 	best rra : %d\n", count.rra);
			count = ft_count_rrop(count);
	printf("		SALADE DE PATATES		\n");
	printf("			count.ra  = %d\n", count.ra);
	printf("			count.rra = %d\n", count.rra);
	printf("			count.rrb = %d\n", count.rrb);
	printf("			count.rr  = %d\n", count.rr);
	printf("			count.rrr = %d\n", count.rrr);
			count = ft_totalcheck(count);
			if (count.total < count.besttotal)
				count = ft_best_count_assign(count);
			tmp = tmp->next;
			adjust++;
		}
		ft_application(a, b, count);
	ft_view(a);
	ft_viewb(b);
	}
	printf("\n	End of best sort\n");
}
