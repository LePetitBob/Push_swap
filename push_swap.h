/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 05:11:17 by vduriez           #+#    #+#             */
/*   Updated: 2021/10/29 12:05:49 by vduriez          ###   ########.fr       */
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

typedef struct s_count
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	bestra;
	int	bestrb;
	int	bestrr;
	int	bestrra;
	int	bestrrb;
	int	bestrrr;
	int	total;
	int	besttotal;
	int	index;
}				t_count;

typedef struct s_data
{
	long	highest;
	long	lowest;
	long	higha;
	long	lowa;
	long	highb;
	long	lowb;
	long	diff;
	long	median;
	char	**args;
	int		nbargs;
	int		si;
	int		sj;
	int		sk;
}			t_data;

typedef struct s_limits
{
	long	highest;
	long	lowest;
	long	higha;
	long	lowa;
	long	highb;
	long	lowb;
	int		sa;
	int		sb;
}			t_limit;

typedef struct s_read
{
	int				index;
	int				check;
	int				read_ret;
	char			*reading;
	char			*line;
}					t_read;

char	*ft_strdup(const char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_free(char *s);
long	ft_atol(char *str);
long	ft_find_median(t_list *a, t_data data);
int		ft_abs(int val);
int		ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_countnbrs(char *str);
int		ft_check_sorted(t_list *a);
int		ft_checkargs(int ac, char **av);
int		ft_smart_move_count(t_list *a, long highest, int direction);
int		ft_sortedbutwrongpos(t_list *a);
int		ft_count_ra(t_list *a, long val, t_count count);
char	*ft_strcpy(char *dest, char *src, unsigned int n);
char	*ft_strdup(const char *s1);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	**ft_split(char const *str, char c, t_data data);
void	ft_clinit(t_list *lista, t_list *listb);
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
void	ft_sa(t_list *list);
void	ft_sb(t_list *list);
void	ft_ss(t_list *a, t_list *b);
void	ft_pa(t_list *a, t_list *b);
void	ft_pb(t_list *a, t_list *b);
void	ft_clear(t_list *lista, t_list *listb);
void	ft_push_swap(t_list *a, t_list *b, t_data data);
void	ft_perfect_sort(t_list *a, t_list *b, t_data data);
void	ft_best_push(t_list *a, t_list *b, t_data data);
void	ft_best_sort(t_list *a, t_list *b);
void	ft_sort3(t_list *a);
void	ft_sort5(t_list *a, t_list *b, t_data data);
void	ft_smart_shift(t_list *a, long lowest);
void	ft_insert_sort(t_list *a, t_list *b, t_data data);
void	ft_smart_rotate(t_list *a, t_list *b, t_limit limits);
void	ft_application(t_list *a, t_list *b, t_count count);
t_data	ft_find_limits(t_list *a, t_data data);
t_count	ft_best_count(t_count count, t_list *a, t_list *b);
t_count	ft_totalcheck(t_count count);
t_count	ft_init_count(void);
t_count	ft_reset_count(t_list *a, long val, t_count count);
t_count	ft_count_rrop(t_count count);
t_count	ft_r_to_rr(t_count count, t_list *a, t_list *b);
t_count	ft_best_count_assign(t_count count);
t_limit	ft_find_limits2(t_list *a, t_list *b, t_limit limits);
t_limit	ft_find_limits3(t_list *a);
t_limit	ft_get_size(t_list *a, t_list *b);
t_limit	ft_limit_compare(t_limit limits);

#endif