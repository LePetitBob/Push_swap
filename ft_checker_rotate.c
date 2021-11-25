/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 21:52:26 by vduriez           #+#    #+#             */
/*   Updated: 2021/11/25 23:27:16 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_chra(t_list *a, t_list *b)
{
	long	tmp;

	if (a->first)
	{
		tmp = a->first->value;
		ft_rmfirst(a);
		ft_addlast(a, tmp);
	}
	else
		ft_exit(a, b);
}

void	ft_chrb(t_list *a, t_list *b)
{
	long	tmp;

	if (b->first)
	{
		tmp = b->first->value;
		ft_rmfirst(b);
		ft_addlast(b, tmp);
	}
	else
		ft_exit(a, b);
}

void	ft_chrr(t_list *a, t_list *b)
{
	long	tmp;

	if (a->first && b->first)
	{
		tmp = a->first->value;
		ft_rmfirst(a);
		ft_addlast(a, tmp);
		tmp = b->first->value;
		ft_rmfirst(b);
		ft_addlast(b, tmp);
	}
	else
		ft_exit(a, b);
}
