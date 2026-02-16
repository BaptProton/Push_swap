/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_ra_rb_rr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:54:20 by bproton           #+#    #+#             */
/*   Updated: 2024/02/21 15:09:17 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ra_rb_rr(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp1;

	if (count_list(*stack) < 2)
		return (0);
	temp = (*stack);
	(*stack) = (*stack)->next;
	temp1 = find_last_node((*stack));
	temp1->next = temp;
	temp->next = NULL;
	return (1);
}

void	ra(t_stack **stack_a)
{
	ra_rb_rr(stack_a);
	write (1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	ra_rb_rr(stack_b);
	write (1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra_rb_rr(stack_a);
	ra_rb_rr(stack_b);
	write (1, "rr\n", 3);
}
