/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_rotate2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 02:57:50 by vduriez           #+#    #+#             */
/*   Updated: 2021/11/25 23:32:05 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_chrra(t_list *a, t_list *b)
{
	long	tmp;

	if (a->first)
	{
		tmp = a->last->value;
		ft_rmlast(a);
		ft_addfirst(a, tmp);
	}
	else
		ft_exit(a, b);
}

void	ft_chrrb(t_list *a, t_list *b)
{
	long	tmp;

	if (b->first)
	{
		tmp = b->last->value;
		ft_rmlast(b);
		ft_addfirst(b, tmp);
	}
	else
		ft_exit(a, b);
}

void	ft_chrrr(t_list *a, t_list *b)
{
	long	tmp;

	if (a->first && b->first)
	{
		tmp = a->last->value;
		ft_rmlast(a);
		ft_addfirst(a, tmp);
		tmp = b->last->value;
		ft_rmlast(b);
		ft_addfirst(b, tmp);
	}
	else
		ft_exit(a, b);
}

void	ft_exit(t_list *a, t_list *b)
{
	write(2, "KO\n", 3);
	ft_clear(a, b);
	exit(1);
}
