/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:54:32 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/19 20:58:48 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	ft_ditto(int ac, char **av)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < ac)
	{
		j = 0;
		k = 0;
		while (j < ac)
		{
			if (ft_atol(av[i]) == ft_atol(av[j]))
				k++;
			j++;
		}
		if (k != 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkint(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (ft_atol(av[i]) < -2147483648 || ft_atol(av[i]) > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	ft_checkargs(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && (av[i][j] != '-' && (av[i][j] < 48 || av[i][j] > 57)))
				return (0);
			if (j != 0 && (av[i][j] < 48 || av[i][j] > 57))
				return (0);
			j++;
		}
		i++;
	}
	if (!ft_checkint(ac, av))
		return (0);
	if (ft_ditto(ac, av))
		return (0);
	return (1);
}

void	ft_clinit(t_list *lista, t_list *listb)
{
	lista->first = NULL;
	lista->last = NULL;
	listb->first = NULL;
	listb->last = NULL;
}

void	ft_clear(t_list *lista, t_list *listb)
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
}

/////////////////////////////////////////////////////////////////////////////////////
/**/void	ft_view(t_list *list)
/**/{
/**/	t_stack	*tmp;
/**/
// /**/	return ;
/**/	if (list->first)
/**/	{
/**/		tmp = list->first;
/**/		printf("\nstack A\n");
/**/		while (tmp)
/**/		{
/**/			printf("%ld\n", tmp->value);
/**/			tmp = tmp->next;
/**/		}
/**/		printf("\n");
/**/	}
/**/}
/**/
/**/void	ft_viewb(t_list *list)
/**/{
/**/	t_stack	*tmp;
/**/
// /**/	return ;
/**/	if (list->first)
/**/	{
/**/		tmp = list->first;
/**/		printf("\n\nstack B\n");
/**/		while (tmp)
/**/		{
/**/			printf("%ld\n", tmp->value);
/**/			tmp = tmp->next;
/**/		}
/**/		printf("\n");
/**/	}
/**/}
/////////////////////////////////////////////////////////////////////////////////////

int	main(int ac, char **av)
{
	t_list	a;
	t_list	b;
	t_data	data;

	(void)ac;
	data.nbargs = ft_countnbrs(av[1]);
	data.args = ft_split(av[1], ' ', data);
	if (ft_checkargs(data.nbargs, data.args) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ft_clinit(&a, &b);
	data.si = data.nbargs - 1;
	while (data.si >= 0)
	{
		ft_addfirst(&a, ft_atol(data.args[data.si]));
		data.si--;
	}
	ft_push_swap(&a, &b, data);
	ft_view(&a);
	ft_viewb(&b);
	ft_clear(&a, &b);
	ft_argsfree(data);
	return (0);
}
