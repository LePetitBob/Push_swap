/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3to5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 03:02:49 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/26 17:51:31 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_smart_move_count(t_list *a, long lowest, int direction)
{
	t_stack	*tmp;
	int		output;

	output = 0;
	if (direction == 1)
	{
		tmp = a->first;
		while (tmp && tmp->value != lowest)
		{
			output++;
			tmp = tmp->next;
		}
		return (output);
	}
	tmp = a->last;
	while (tmp && tmp->value != lowest)
	{
		output++;
		tmp = tmp->prev;
	}
	return (output);
}

void	ft_smart_shift(t_list *a, long lowest)
{
	int	ra;
	int	rra;

	ra = ft_smart_move_count(a, lowest, 1);
	rra = ft_smart_move_count(a, lowest, -1);
	if (rra < ra)
	{
		while (rra >= 0)
		{
			ft_rra(a);
			rra--;
		}
		return ;
	}
	while (ra > 0)
	{
		ft_ra(a);
		ra--;
	}
}

void	ft_sort3(t_list *a)
{
	if (a->last->value > a->first->value
		&& a->last->value > a->first->next->value)
	{
		ft_sa(a);
		return ;
	}
	if (a->first->next->value > a->last->value
		&& a->first->next->value > a->first->value)
	{
		ft_rra(a);
		if (ft_check_sorted(a))
			return ;
		ft_sa(a);
		return ;
	}
	if (a->first->value > a->first->next->value
		&& a->first->value > a->last->value)
	{
		ft_ra(a);
		if (ft_check_sorted(a))
			return ;
		ft_sa(a);
	}
}

void	ft_sort5(t_list *a, t_list *b, t_data data)
{
	t_limit	limits;

	while (data.nbargs > 3)
	{
		limits = ft_find_limits3(a);
		if (a->first->value == limits.lowa)
		{
			ft_pb(a, b);
			data.nbargs--;
		}
		else
			ft_smart_rotate(a, b, limits);
	}
	if (!ft_check_sorted(a))
		ft_sort3(a);
	ft_insert_sort(a, b, data);
}
