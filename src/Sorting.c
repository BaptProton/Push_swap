/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:16:39 by bproton           #+#    #+#             */
/*   Updated: 2024/02/23 13:26:25 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	rotate_a(t_stack **s_a, t_stack *cheapest)
{
	while (cheapest != *s_a)
	{
		if (cheapest->above == 0)
			ra(s_a);
		else
			rra(s_a);
	}
}

static	void	rotate_b(t_stack **s_b, t_stack *cheapest)
{
	while (cheapest != *s_b)
	{
		if (cheapest->above == 0)
			rb(s_b);
		else
			rrb(s_b);
	}
}

void	final_sort(t_stack **s_a, t_stack **s_b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(s_b);
	if ((cheapest->above == 0 && cheapest->target->above == 0)
		|| (cheapest->above == 1 && cheapest->target->above == 1))
	{
		while (cheapest != *s_b && cheapest->target != *s_a)
		{
			if (cheapest->above == 0 && cheapest->target->above == 0)
				rr(s_a, s_b);
			else if (cheapest->above == 1 && cheapest->target->above == 1)
				rrr(s_a, s_b);
		}
	}
	if (cheapest->target != *s_a)
		rotate_a(s_a, cheapest->target);
	if (cheapest != *s_b)
		rotate_b(s_b, cheapest);
	pa(s_a, s_b);
}

void	small_stack_sort(t_stack **st)
{
	if ((*st)->value > (*st)->next->value
		&& (*st)->value > (*st)->next->next->value)
		ra(st);
	else if ((*st)->value < (*st)->next->value
		&& (*st)->next->value > (*st)->next->next->value)
		rra(st);
	if ((*st)->value > (*st)->next->value)
		sa(st);
}

void	big_sort(t_stack **s_a)
{
	t_stack	*s_b;
	t_count	length;

	s_b = NULL;
	length.len_a = 3;
	length.len_b = 0;
	while ((*s_a)->next->next->next != NULL)
	{
		pb(s_a, &s_b);
		length.len_b += 1;
	}
	small_stack_sort(s_a);
	while (s_b != NULL)
	{
		set_target(*s_a, s_b);
		get_index_above(s_a, &s_b, &length);
		count_cost(&s_b, &length);
		final_sort(s_a, &s_b);
		length.len_a += 1;
		length.len_b -= 1;
	}
	smallest_first(s_a);
}
