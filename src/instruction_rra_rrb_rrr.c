/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rra_rrb_rrr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:18:02 by bproton           #+#    #+#             */
/*   Updated: 2024/02/21 15:08:48 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	rra_rrb_rrr(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp_head;

	temp_head = (*stack);
	temp = find_last_node(*stack);
	while ((*stack)->next->next != NULL)
		(*stack) = (*stack)->next;
	(*stack)->next = NULL;
	temp->next = temp_head;
	(*stack) = temp;
}

void	rra(t_stack **stack_a)
{
	rra_rrb_rrr(stack_a);
	write (1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	rra_rrb_rrr(stack_b);
	write (1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra_rrb_rrr(stack_a);
	rra_rrb_rrr(stack_b);
	write (1, "rrr\n", 4);
}
