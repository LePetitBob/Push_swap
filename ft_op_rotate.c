/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:52:26 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/06 02:58:02 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list *list)
{
	long	tmp;

	tmp = list->first->value;
	ft_rmfirst(list);
	ft_addlast(list, tmp);
	write(1, "ra\n", 3);
}

void	ft_rb(t_list *list)
{
	long	tmp;

	tmp = list->first->value;
	ft_rmfirst(list);
	ft_addlast(list, tmp);
	write(1, "rb\n", 3);
}

void	ft_rr(t_list *a, t_list *b)
{
	long	tmp;

	tmp = a->first->value;
	ft_rmfirst(a);
	ft_addlast(a, tmp);
	tmp = b->first->value;
	ft_rmfirst(b);
	ft_addlast(b, tmp);
	write(1, "rr\n", 3);
}
