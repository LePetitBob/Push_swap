/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:51:32 by vduriez           #+#    #+#             */
/*   Updated: 2021/11/25 23:28:48 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	application(t_list *a, t_list *b, char *op)
{
	if (!ft_strcmp("ra\n", op))
		ft_chra(a, b);
	if (!ft_strcmp("rb\n", op))
		ft_chrb(a, b);
	if (!ft_strcmp("rr\n", op))
		ft_chrr(a, b);
	if (!ft_strcmp("rra\n", op))
		ft_chrra(a, b);
	if (!ft_strcmp("rrb\n", op))
		ft_chrrb(a, b);
	if (!ft_strcmp("rrr\n", op))
		ft_chrrr(a, b);
	if (!ft_strcmp("pa\n", op))
		ft_chpa(a, b);
	if (!ft_strcmp("pb\n", op))
		ft_chpb(a, b);
	if (!ft_strcmp("sa\n", op))
		ft_chsa(a, b);
	if (!ft_strcmp("sb\n", op))
		ft_chsb(a, b);
	if (!ft_strcmp("ss\n", op))
		ft_chss(a, b);
}

void	check_order(t_list *a, t_list *b)
{
	t_stack	*tmp;

	if (b->first)
	{
		write(2, "KO\n", 3);
		return ;
	}
	tmp = a->first;
	while (tmp)
	{
		if (tmp->next && tmp->value > tmp->next->value)
		{
			write(2, "KO\n", 3);
			ft_clear(a, b);
			return ;
		}
		tmp = tmp->next;
	}
	write(1, "OK\n", 3);
	ft_clear(a, b);
}

void	get_cl(t_list *a, t_list *b, int ac, char **av)
{
	int	i;

	i = 0;
	ft_clinit(a, b);
	i = ac - 1;
	while (i >= 1)
	{
		ft_addfirst(a, ft_atol(av[i]));
		i--;
	}
}

void	error_management(t_list *a, t_list *b, char *op)
{
	write(2, "Error\n", 6);
	free(op);
	ft_clear(a, b);
}

int	main(int ac, char **av)
{
	t_list	a;
	t_list	b;
	char	*op;

	if (ac < 2)
		return (0);
	op = get_next_line(0);
	if ((op && op[0] == 'E') || !ft_checkerargs(ac, av))
		error_management(&a, &b, op);
	if ((op && op[0] == 'E') || !ft_checkerargs(ac, av))
		return (0);
	get_cl(&a, &b, ac, av);
	while (1)
	{
		if (op)
			application(&a, &b, op);
		free(op);
		if (!op)
			break ;
		op = get_next_line(0);
	}
	check_order(&a, &b);
	return (0);
}
