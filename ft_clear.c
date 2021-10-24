/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:50:12 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/23 15:51:02 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear(t_list *lista, t_list *listb, t_data data)
{
	t_stack	*tmp;
	t_stack	*index;

	if (lista)
	{
		index = lista->first;
		while (index)
		{
			tmp = index;
			index = index->next;
			free(tmp);
		}
	}
	if (listb)
	{
		index = listb->first;
		while (index)
		{
			tmp = index;
			index = index->next;
			free(tmp);
		}
	}
	ft_argsfree(data);
}
