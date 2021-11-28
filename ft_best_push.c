/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_best_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 02:40:00 by vduriez           #+#    #+#             */
/*   Updated: 2021/11/27 18:31:54 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nbmm_pb(int nb, t_list *a, t_list *b)
{
	ft_pb(a, b);
	nb--;
	return (nb);
}

int	ft_first_chunk(t_list *a, t_list *b, t_data data)
{
	if (a->first->value < data.median && a->first->value != data.highest
		&& a->first->value != data.lowest)
		data.nbargs = ft_nbmm_pb(data.nbargs, a, b);
	else
		ft_ra(a);
	return (data.nbargs);
}

int	ft_last_chunk(t_list *a, t_list *b, t_data data)
{
	if (a->first->value != data.median && a->first->value != data.highest
		&& a->first->value != data.lowest)
		ft_pb(a, b);
	else
		ft_ra(a);
	return (data.nbargs);
}

int	ft_chunk(t_list *a, t_list *b, t_data data)
{
	if (a->first->value < data.si && a->first->value != data.highest
		&& a->first->value != data.lowest && a->first->value != data.median)
		data.nbargs = ft_nbmm_pb(data.nbargs, a, b);
	else
		ft_ra(a);
	return (data.nbargs);
}

void	ft_best_push(t_list *a, t_list *b, t_data data)
{
	data.sk = -1;
	data.median = ft_find_median(a, data);
	while (++data.sk < data.nbargs)
		data.nbargs = ft_first_chunk(a, b, data);
	data.sk = -1;
	data.si = ft_find_median(a, data);
	while (++data.sk < data.nbargs)
		data.nbargs = ft_chunk(a, b, data);
	data.sk = -1;
	data.si = ft_find_median(a, data);
	while (++data.sk < data.nbargs)
		data.nbargs = ft_chunk(a, b, data);
	data.sk = -1;
	data.si = ft_find_median(a, data);
	while (++data.sk < data.nbargs)
		data.nbargs = ft_chunk(a, b, data);
	data.sk = -1;
	while (++data.sk < data.nbargs)
		data.nbargs = ft_last_chunk(a, b, data);
	if (!ft_check_sorted(a))
		ft_sort3(a);
	ft_best_sort(a, b);
}
