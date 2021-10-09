/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perfect_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:51:10 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/09 08:28:46 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(t_list *a)
{
	if (a->last->value < a->first->value
		&& a->last->value < a->first->next->value)
	{
		ft_sa(a);
		return ;
	}
	if (a->last->value > a->first->next->value
		&& a->last->value > a->first->next->value)
	{
		ft_rra(a);
		if (ft_check_sorted(a))
			return ;
		ft_sa(a);
		return ;
	}
	if (a->first->value < a->first->next->value
		&& a->first->value < a->last->value)
	{
		ft_ra(a);
		if (ft_check_sorted(a))
			return ;
		ft_sa(a);
		return ;
	}
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
	if (data.nbargs >= 5)
	{
		ft_sort5(a);
		return ;
	}
}
