/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smart_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 01:27:55 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/24 22:40:55 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_smart_rotate(t_list *a, t_list *b, t_limit limits)
{
	t_stack	*tmp;
	int		ri;
	int		rri;

	ri = 0;
	tmp = a->first;
	limits = ft_get_size(a, b);
	while (tmp && tmp->value != limits.lowa)
	{
		ri++;
		tmp = tmp->next;
	}
	rri = limits.sizea - ri;
	if (ri < rri)
	{
		ft_ra(a);
		return ;
	}
	ft_rra(a);
}