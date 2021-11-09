/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 05:04:29 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/29 12:30:23 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_list *a, t_list *b)
{
	long	tmp;

	tmp = b->first->value;
	ft_rmfirst(b);
	ft_addfirst(a, tmp);
}

void	ft_pb(t_list *a, t_list *b)
{
	long	tmp;

	tmp = a->first->value;
	ft_rmfirst(a);
	ft_addfirst(b, tmp);
}

void	ft_sa(t_list *a)
{
	long	tmp;
	long	tmp2;

	tmp = a->first->value;
	ft_rmfirst(a);
	tmp2 = a->first->value;
	ft_rmfirst(a);
	ft_addfirst(a, tmp);
	ft_addfirst(a, tmp2);
}

void	ft_sb(t_list *b)
{
	long	tmp;
	long	tmp2;

	tmp = b->first->value;
	ft_rmfirst(b);
	tmp2 = b->first->value;
	ft_rmfirst(b);
	ft_addfirst(b, tmp);
	ft_addfirst(b, tmp2);
}

void	ft_ss(t_list *a, t_list *b)
{
	ft_sa(a);
	ft_sb(b);
}
