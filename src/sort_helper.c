/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:06:15 by bproton           #+#    #+#             */
/*   Updated: 2024/02/23 13:26:23 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_smallest(t_stack *stacka)
{
	t_stack	*tempa;
	t_stack	*smallest;
	long	i;

	tempa = stacka;
	i = LONG_MAX;
	while (tempa != NULL)
	{
		if (tempa->value < i)
		{
			i = tempa->value;
			smallest = tempa;
		}
		tempa = tempa->next;
	}
	return (smallest);
}

void	smallest_first(t_stack **stacka)
{
	t_stack	*smallest;

	smallest = find_smallest(*stacka);
	while ((*stacka) != smallest)
	{
		if (smallest->above == 0)
			ra(stacka);
		else
			rra(stacka);
	}
}

void	set_target(t_stack *stacka, t_stack *stackb)
{
	t_stack	*tempa;
	t_stack	*target_node;
	long	val_a;

	while (stackb != NULL)
	{
		tempa = stacka;
		val_a = LONG_MAX;
		while (tempa)
		{
			if (tempa->value > stackb->value && tempa->value < val_a)
			{
				val_a = tempa->value;
				target_node = tempa;
			}
			tempa = tempa->next;
		}
		if (val_a == LONG_MAX)
			stackb->target = find_smallest(stacka);
		else
			stackb->target = target_node;
		stackb = stackb->next;
	}
}

t_stack	*find_cheapest(t_stack **s_b)
{
	t_stack	*tempb;
	int		cost;

	tempb = *s_b;
	cost = tempb->cost;
	while (tempb != NULL)
	{
		if (cost > tempb->cost)
			cost = tempb->cost;
		tempb = tempb->next;
	}
	tempb = *s_b;
	while (tempb->cost != cost)
		tempb = tempb->next;
	return (tempb);
}

void	count_cost(t_stack **s_b, t_count *len)
{
	t_stack	*tempb;

	tempb = (*s_b);
	while (tempb != NULL)
	{
		if (tempb->above == 0 && tempb->target->above == 0)
				tempb->cost = (tempb->index + tempb->target->index);
		else if (tempb->above == 1 && tempb->target->above == 1)
				tempb->cost = ((len->len_b - tempb->index)
					+ (len->len_a - tempb->target->index));
		else
		{
			if (tempb->above == 1 && tempb->target->above == 0)
				tempb->cost = ((len->len_b - tempb->index)
						+ tempb->target->index + 1);
			else
				tempb->cost = (tempb->index + (len->len_a
							- tempb->target->index) + 2);
		}
		tempb = tempb->next;
	}
}
