/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 00:29:49 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/07 16:37:20 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoi(char *str)
{
	long	i;
	long	signe;
	long	somme;

	i = 0;
	signe = 1;
	somme = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		signe = -1;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		somme = 10 * somme + (str[i] - 48);
		i++;
	}
	return (somme * signe);
}
