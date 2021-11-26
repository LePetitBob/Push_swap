/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortedbutwrongpos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:06:09 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/13 11:16:18 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sortedbutwrongpos(t_list *a)
{
	t_stack	*tmp;
	int		wrong;

	wrong = 0;
	tmp = a->first->next;
	while (tmp)
	{
		if (tmp->prev->value > tmp->value)
			wrong++;
		tmp = tmp->next;
	}
	if (wrong > 1)
		return (0);
	return (1);
}
