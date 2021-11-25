/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 05:04:29 by vduriez           #+#    #+#             */
/*   Updated: 2021/11/25 23:29:25 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_chpa(t_list *a, t_list *b)
{
	long	tmp;

	if (b->first)
	{
		tmp = b->first->value;
		ft_rmfirst(b);
		ft_addfirst(a, tmp);
	}
	else
		ft_exit(a, b);
}

void	ft_chpb(t_list *a, t_list *b)
{
	long	tmp;

	if (a->first)
	{
		tmp = a->first->value;
		ft_rmfirst(a);
		ft_addfirst(b, tmp);
	}
	else
		ft_exit(a, b);
}

void	ft_chsa(t_list *a, t_list *b)
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
	}
	else
		ft_exit(a, b);
}

void	ft_chsb(t_list *a, t_list *b)
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
	}
	else
		ft_exit(a, b);
}

void	ft_chss(t_list *a, t_list *b)
{
	if (a->first && a->first->next && b->first && b->first->next)
	{
		ft_chsa(a, b);
		ft_chsb(a, b);
	}
	else
		ft_exit(a, b);
}
