/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_rotate2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 02:57:50 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/29 12:30:09 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list *list)
{
	long	tmp;

	tmp = list->last->value;
	ft_rmlast(list);
	ft_addfirst(list, tmp);
}

void	ft_rrb(t_list *list)
{
	long	tmp;

	tmp = list->last->value;
	ft_rmlast(list);
	ft_addfirst(list, tmp);
}

void	ft_rrr(t_list *a, t_list *b)
{
	long	tmp;

	tmp = a->last->value;
	ft_rmlast(a);
	ft_addfirst(a, tmp);
	tmp = b->last->value;
	ft_rmlast(b);
	ft_addfirst(b, tmp);
}
