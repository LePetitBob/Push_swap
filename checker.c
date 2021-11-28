/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:51:32 by vduriez           #+#    #+#             */
/*   Updated: 2021/11/28 18:43:16 by vduriez          ###   ########.fr       */
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

int	wrong_command(char *op)
{
	if (ft_strcmp("ra\n", op) && ft_strcmp("rb\n", op)
		&& ft_strcmp("rr\n", op) && ft_strcmp("rra\n", op)
		&& ft_strcmp("rrb\n", op) && ft_strcmp("rrr\n", op)
		&& ft_strcmp("pa\n", op) && ft_strcmp("pb\n", op)
		&& ft_strcmp("sa\n", op) && ft_strcmp("sb\n", op)
		&& ft_strcmp("ss\n", op))
		return (1);
	printf("boop\n");
	return (0);
}

void	check_order(t_list *a, t_list *b, int print)
{
	t_stack	*tmp;

	if (b->first)
	{
		write(2, "KO\n", 3 * print);
		return ;
	}
	tmp = a->first;
	while (tmp)
	{
		if (tmp->next && tmp->value > tmp->next->value)
		{
			write(2, "KO\n", 3 * print);
			ft_clear(a, b);
			return ;
		}
		tmp = tmp->next;
	}
	write(1, "OK\n", 3 * print);
	ft_clear(a, b);
	exit(0);
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

int	main(int ac, char **av)
{
	t_list	a;
	t_list	b;
	char	*op;

	if (ac < 2)
		return (0);
	if (!ft_checkerargs(ac, av))
		error_management(&a, &b);
	op = get_next_line(0);
	if (!op)
		empty_management(&a, &b, op);
	get_cl(&a, &b, ac, av);
	if (wrong_command(op))
		wrong_management(&a, &b, op);
	while (1)
	{
		if (op)
			application(&a, &b, op);
		free(op);
		if (!op)
			break ;
		op = get_next_line(0);
	}
	check_order(&a, &b, 1);
	return (0);
}
