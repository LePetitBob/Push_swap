/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:38:26 by vduriez           #+#    #+#             */
/*   Updated: 2021/11/28 18:42:33 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	empty_management(t_list *a, t_list *b, char *op)
{
	if (!b->first && a->first)
		check_order(a, b, 0);
	free(op);
	exit(1);
}

void	error_management(t_list *a, t_list *b)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	wrong_management(t_list *a, t_list *b, char *op)
{
	write(2, "Error\n", 6);
	free(op);
	ft_clear(a, b);
	exit(1);
}
