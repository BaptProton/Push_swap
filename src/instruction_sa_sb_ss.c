/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_sa_sb_ss.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:26:10 by bproton           #+#    #+#             */
/*   Updated: 2024/02/21 15:08:36 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sa_sb_ss(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp1;

	if (stack == NULL || (*stack)->next == NULL)
		return ;
	temp1 = (*stack);
	temp = (*stack)->next;
	temp1->next = temp->next;
	(*stack) = temp;
	(*stack)->next = temp1;
}

void	sa(t_stack **stack_a)
{
	sa_sb_ss(stack_a);
	write (1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	sa_sb_ss(stack_b);
	write (1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa_sb_ss(stack_a);
	sa_sb_ss(stack_b);
	write (1, "ss\n", 3);
}
