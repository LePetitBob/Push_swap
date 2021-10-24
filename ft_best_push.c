/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 02:40:00 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/24 14:57:08 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_best_push(t_list *a, t_list *b, t_data data)
{
	long	i;
	long	j;

	i = 0;
	j = 0;
	data.median = ft_find_median(a, data);
	while (i < data.nbargs)
	{
		if (a->first->value < data.median && a->first->value != data.highest
			&& a->first->value != data.lowest)
		{
		// 	j++;
			ft_pb(a, b);
		}
		// else
		// 	ft_ra(a);
		i++;
	}
	/*i = 0;
	data.si = ft_find_median(a, data);
	while (i < data.nbargs - j)
	{
		if (a->first->value < data.si && a->first->value != data.highest
			&& a->first->value != data.lowest && a->first->value != data.median)
		{
			j++;
			ft_pb(a, b);
		}
		else
			ft_ra(a);
		i++;
	}
	i = 0;
	data.si = ft_find_median(a, data);
	while (i < data.nbargs - j)
	{
		if (a->first->value < data.si && a->first->value != data.highest
			&& a->first->value != data.lowest && a->first->value != data.median)
		{
			j++;
			ft_pb(a, b);
		}
		else
			ft_ra(a);
		i++;
	}
	i = 0;
	data.si = ft_find_median(a, data);
	while (i < data.nbargs - j)
	{
		if (a->first->value < data.si && a->first->value != data.highest
			&& a->first->value != data.lowest && a->first->value != data.median)
		{
			j++;
			ft_pb(a, b);
		}
		else
			ft_ra(a);
		i++;
	}
	i = 0;
	while (i < data.nbargs - j)
	{
		if (a->first->value != data.median && a->first->value != data.highest
			&& a->first->value != data.lowest)
			ft_pb(a, b);
		else
			ft_ra(a);
		i++;
	}*/
	if (!ft_check_sorted(a))
		ft_sort3(a);
	ft_best_sort(a, b);
}
