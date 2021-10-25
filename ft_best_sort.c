/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:58:31 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/25 19:41:40 by vduriez          ###   ########.fr       */
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

int	ft_good_to_pa(t_list *a, long val, t_stack *a1, t_stack *a2)
{
	t_limit	limits;

	limits = ft_find_limits3(a);
	if ((val > limits.higha && a1->value == limits.lowa)
		|| (val < a1->value	&& a1->value == limits.lowa))
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
		|| (val < a1->value	&& a1->value == limits.lowa))
		return (1);
	if ((val > a1->value && val < a2->value)
		&& (a1->value != limits.higha || a2->value != limits.lowa))
		return (1);
	return (0);
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

t_count	ft_best_count_assign(t_count count)
{
	count.bestra = count.ra;
	count.bestrb = count.rb;
	count.bestrra = count.rra;
	count.bestrrb = count.rrb;
	count.bestrr = count.rr;
	count.bestrrr = count.rrr;
						// printf("	FT_BEST_COUNT_ASSIGN\n");
						// printf("		Count ra = %d\n", count.ra);
						// printf("		Count rb = %d\n", count.rb);
						// printf("		Count rr = %d\n", count.rr);
						// printf("		Count rra = %d\n", count.rra);
						// printf("		Count rrb = %d\n", count.rrb);
						// printf("		Count rrr = %d\n", count.rrr);
						// printf("		Count total = %d\n", count.total);
						// printf("		Count besttotal = %d\n", count.besttotal);
						// getchar();
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
	t_limit	limits;

	limits = ft_get_size(a, b);
	if ((limits.sizea - count.ra) + 1 < count.ra)
	{
		count.rra = (limits.sizea - count.ra);
		count.ra = 0;
	}
	if ((limits.sizeb - count.rb) + 1 < count.rb)
	{
		count.rrb = (limits.sizeb - count.rb);
		count.rb = 0;
	}
	return (count);
}

void	ft_best_sort(t_list *a, t_list *b)
{
	t_stack	*tmp;
	t_count	count;
	t_limit	limits;
	int		index;

	while (b->first)
	{
		index = 0;
		limits = ft_find_limits3(b);
		count = ft_initcount();
		tmp = b->first;
		if (!ft_good_to_pa(a, b->first->value, a->first, a->last))
		{
			while (tmp)
			{
				if(index <= count.besttotal || (limits.sizea - index) <= count.besttotal)
				{
					count = ft_reset_count(count);
					count.ra = ft_count_ra(a, tmp->value, count);
					count.rb += index;
					count = ft_r_to_rr(count, a, b);
					count = ft_count_rrop(count);
					count = ft_totalcheck(count);
				}
				tmp = tmp->next;
				index++;
			}
		}
		ft_application(a, b, count);
	}
}

// void	ft_best_sort(t_list *a, t_list *b)
// {
// 	t_stack	*tmp;
// 	t_count	count;
// 	t_limit	limits;
// 	int		index;

// 	while (b->first)
// 	{
// 		index = 0;
// 		limits = ft_find_limits3(b);
// 		count = ft_initcount();
// 		tmp = b->first;
// 		if (!ft_good_to_pa(a, b->first->value, a->first, a->last))
// 		{
// 			while (tmp)
// 			{
// 				// if (!count.besttotal || (limits.sizea - index) < count.besttotal)
// 				// {
// 					count = ft_reset_count(count);
// 					count.ra = ft_count_ra(a, tmp->value, count);
// 					count.rb += index;
// 					count = ft_r_to_rr(count, a, b);
// 					count = ft_count_rrop(count);
// 					count = ft_totalcheck(count);
// 						// printf("	FT_BEST_COUNT_ASSIGN\n");
// 						// printf("		Count ra = %d\n", count.ra);
// 						// printf("		Count rb = %d\n", count.rb);
// 						// printf("		Count rr = %d\n", count.rr);
// 						// printf("		Count rra = %d\n", count.rra);
// 						// printf("		Count rrb = %d\n", count.rrb);
// 						// printf("		Count rrr = %d\n", count.rrr);
// 						// printf("		Count total = %d\n", count.total);
// 						// printf("		Count besttotal = %d\n", count.besttotal);
// 						// getchar();
// 				tmp = tmp->next;
// 				index++;
// 			}
// 		}
// 		ft_application(a, b, count);
// 	}
// }
