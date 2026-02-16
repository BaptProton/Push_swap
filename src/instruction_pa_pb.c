/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_pa_pb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:24:28 by bproton           #+#    #+#             */
/*   Updated: 2024/02/22 12:36:38 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pa_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (!(*stack_a))
		return ;
	if (!(*stack_b))
	{
		(*stack_b) = (*stack_a);
		temp = (*stack_a)->next;
		(*stack_a)->next = NULL;
		(*stack_a) = temp;
	}
	else
	{
		temp2 = (*stack_a);
		temp = (*stack_a)->next;
		temp2->next = (*stack_b);
		(*stack_b) = temp2;
		(*stack_a) = temp;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	pa_pb(stack_b, stack_a);
	write (1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	pa_pb(stack_a, stack_b);
	write (1, "pb\n", 3);
}
