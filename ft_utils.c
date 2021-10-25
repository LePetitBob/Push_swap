/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:50:29 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/24 17:35:40 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_countnbrs(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == 32)
			i++;
		if (str[i] != 32)
		{
			j++;
			i++;
		}
		while (str[i] && str[i] != 32)
			i++;
	}
	return (j);
}
