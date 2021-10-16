/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:58:31 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/16 21:17:48 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_count	ft_initcount(t_count count)
{
	count.ra = 0;
	count.rb = 0;
	count.rr = 0;
	count.rra = 0;
	count.rrb = 0;
	count.rrr = 0;
}

t_limit	ft_sizeofstack(t_list *a, t_list *b)
{
	t_limit limits;
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

int	ft_count_a_to_pb(t_list *a, t_list *b)
{
	t_stack	*tmpa;
	t_stack	*tmpb;
	int		i;
	int		j;

	tmpa = a->first;
	tmpb = b->first;
	while (tmp)
}

void	ft_best_sort(t_list *a, t_list *b, t_data data)
{
	t_count count;
	t_limit	limits;
	t_stack	*tmp;

	count = ft_initcount(count);
	while(ft_check_sorted(a) && !(b->first))
	{
		limits = ft_sizeofstack(a, b);
		tmp = b->first;
		count.ra = ft_count_a_to_pb(a, b);
		while ()
		{
			
		}
	}
}