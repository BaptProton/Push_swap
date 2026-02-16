/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:05:14 by bproton           #+#    #+#             */
/*   Updated: 2026/02/16 14:53:43 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "libft.h"

typedef struct s_count
{
	int				len_a;
	int				len_b;
}				t_count;

typedef struct s_stack	t_stack;

struct	s_stack
{
	int				value;
	int				index;
	int				cost;
	int				above;
	t_stack			*target;
	struct s_stack	*next;
};

int		check_errors_in_str(char *str);
void	add_node(t_stack **stack, int i);
t_stack	*find_last_node(t_stack *stack_a_b);
int		check_same_numbers(long num, t_stack *stack_a);
int		transform_into_list(t_stack **stack_a, char **final_string);
int		free_entire_list(t_stack **stack_a);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_a);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_a);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	small_stack_sort(t_stack **st);
void	count_stack_length(t_stack **stack_a);
int		count_list(t_stack *stack);
void	big_sort(t_stack **s_a);
void	get_index_above(t_stack **stack_a, t_stack **stack_b, t_count *len);
void	count_cost(t_stack **s_b, t_count *len);
void	set_target(t_stack *stacka, t_stack *stackb);
void	final_sort(t_stack **s_a, t_stack **s_b);
t_stack	*find_cheapest(t_stack **s_b);
void	smallest_first(t_stack **stacka);
int		free_board(char **temp);
int		is_sorted(t_stack *stack_a);

#endif