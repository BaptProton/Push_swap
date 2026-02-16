/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_related.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:13:52 by bproton           #+#    #+#             */
/*   Updated: 2024/02/23 13:46:06 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_stack **stack_a, int i)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = i;
	new_node->next = NULL;
	if (!*stack_a)
		*stack_a = new_node;
	else
		find_last_node(*stack_a)->next = new_node;
}

t_stack	*find_last_node(t_stack *stack_a_b)
{
	if (!stack_a_b)
		return (stack_a_b);
	while (stack_a_b->next != NULL)
		stack_a_b = stack_a_b->next;
	return (stack_a_b);
}

int	free_entire_list(t_stack **stack_a)
{
	t_stack	*temp;

	while (*stack_a != NULL)
	{
		temp = (*stack_a)->next;
		free(*stack_a);
		*stack_a = temp;
	}
	free(*stack_a);
	*stack_a = NULL;
	return (0);
}

int	count_list(t_stack *stack)
{
	int	i;

	i = 1;
	while (stack->next != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	get_index_above(t_stack **stack_a, t_stack **stack_b, t_count *len)
{
	t_stack	*temp;
	int		i;

	i = 1;
	temp = (*stack_a);
	while (temp != NULL)
	{
		temp->index = i++;
		if ((len->len_a / 2 + 1) < temp->index)
			temp->above = 1;
		else
			temp->above = 0;
		temp = temp->next;
	}
	i = 1;
	temp = (*stack_b);
	while (temp != NULL)
	{
		temp->index = i++;
		if ((len->len_b / 2 + 1) < temp->index)
			temp->above = 1;
		else
			temp->above = 0;
		temp = temp->next;
	}
}
