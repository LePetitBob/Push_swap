/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilscl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 16:28:10 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/12 00:16:06 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_elem(long value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_addfirst(t_list *list, long value)
{
	t_stack	*a;

	a = ft_create_elem(value);
	if (list->first != NULL)
	{
		list->first->prev = a;
		a->next = list->first;
	}
	else
		a->next = NULL;
	if (list->last == NULL)
		list->last = a;
	list->first = a;
}

void	ft_addlast(t_list *list, long value)
{
	t_stack	*a;

	a = ft_create_elem(value);
	a->value = value;
	a->next = NULL;
	if (list->last)
	{
		list->last->next = a;
		a->prev = list->last;
	}
	else
		a->next = NULL;
	if (!(list->first))
		list->first = a;
	list->last = a;
}

void	ft_rmfirst(t_list *list)
{
	t_stack	*tmp;

	if (!(list->first))
		return ;
	tmp = list->first;
	if (list->first != list->last)
	{
		list->first = list->first->next;
		list->first->prev = NULL;
	}
	else
	{
		list->first = NULL;
		list->last = NULL;
	}
	free(tmp);
}

void	ft_rmlast(t_list *list)
{
	t_stack	*tmp;

	if (!list->last)
		return ;
	tmp = list->last;
	if (list->last != list->first)
	{
		list->last = list->last->prev;
		list->last->next = NULL;
	}
	else
	{
		list->first = NULL;
		list->last = NULL;
	}
	free(tmp);
}
