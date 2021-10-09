/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 05:11:17 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/09 08:28:55 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	long			value;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct s_list
{
	t_stack	*first;
	t_stack	*last;
}				t_list;

typedef struct s_data
{
	long	highest;
	long	lowest;
	long	diff;
	long	median;
	char	**args;
	int		nbargs;
	int		si;
	int		sj;
	int		sk;
}			t_data;


//////////////////////////////////
void	ft_view(t_list *list);
//////////////////////////////////

void	ft_addfirst(t_list *list, long value);
void	ft_addlast(t_list *list, long value);
void	ft_rmfirst(t_list *list);
void	ft_rmlast(t_list *list);
void	ft_ra(t_list *list);
void	ft_rb(t_list *list);
void	ft_rr(t_list *a, t_list *b);
void	ft_rra(t_list *list);
void	ft_rrb(t_list *list);
void	ft_rrr(t_list *a, t_list *b);
void	ft_pa(t_list *a, t_list *b);
void	ft_pb(t_list *a, t_list *b);
void	ft_sa(t_list *list);
void	ft_sb(t_list *list);
char	*ft_strcpy(char *dest, char *src, unsigned int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *s);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	**ft_split(char const *str, char c, t_data data);
int		ft_countnbrs(char *str);
void	ft_push_swap(t_list *a, t_list *b, t_data data);
int		ft_check_sorted(t_list *a);
void	ft_perfect_sort(t_list *a, t_list *b, t_data data);
void	ft_argsfree(t_data data);
#endif
