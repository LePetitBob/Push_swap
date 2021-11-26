/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 05:04:29 by vduriez           #+#    #+#             */
/*   Updated: 2021/11/25 22:52:35 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_list *a, t_list *b)
{
	long	tmp;

	if (b->first)
	{
		tmp = b->first->value;
		ft_rmfirst(b);
		ft_addfirst(a, tmp);
		write(1, "pa\n", 3);
	}
}

void	ft_pb(t_list *a, t_list *b)
{
	long	tmp;

	if (a->first)
	{
		tmp = a->first->value;
		ft_rmfirst(a);
		ft_addfirst(b, tmp);
		write(1, "pb\n", 3);
	}
}

void	ft_sa(t_list *a)
{
	long	tmp;
	long	tmp2;

	if (a->first && a->first->next)
	{
		tmp = a->first->value;
		ft_rmfirst(a);
		tmp2 = a->first->value;
		ft_rmfirst(a);
		ft_addfirst(a, tmp);
		ft_addfirst(a, tmp2);
		write(1, "sa\n", 3);
	}
}

void	ft_sb(t_list *b)
{
	long	tmp;
	long	tmp2;

	if (b->first && b->first->next)
	{
		tmp = b->first->value;
		ft_rmfirst(b);
		tmp2 = b->first->value;
		ft_rmfirst(b);
		ft_addfirst(b, tmp);
		ft_addfirst(b, tmp2);
		write(1, "sb\n", 3);
	}
}

void	ft_ss(t_list *a, t_list *b)
{
	if (a->first && a->first->next && b->first && b->first->next)
	{
		ft_sa(a);
		ft_sb(b);
		write(1, "ss\n", 3);
	}
}
