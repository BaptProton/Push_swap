/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:04:57 by bproton           #+#    #+#             */
/*   Updated: 2026/02/17 12:03:52 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	count_stack_length(t_stack **stack_a)
{
	int	i;

	if (!is_sorted(*stack_a))
	{
		i = count_list(*stack_a);
		if (i == 1)
			return ;
		else if (i == 2)
		{
			if ((*stack_a)->value > (*stack_a)->next->value)
				sa(stack_a);
		}
		else if (i == 3)
			small_stack_sort(stack_a);
		else
			big_sort(stack_a);
	}
}

int	transform_into_list(t_stack **stack_a, char **final_string)
{
	int		i;
	long	num;

	i = -1;
	while (final_string[++i] != NULL)
	{
		if (!check_errors_in_str(final_string[i]))
			return (0);
		num = ft_atoi(final_string[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			write (1, "Error\n", 6);
			return (0);
		}
		if (!check_same_numbers(num, *stack_a))
			return (0);
		add_node(stack_a, num);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	char	**temp;

	stack_a = NULL;
	temp = NULL;
	if (argc < 2 || !argv[1][0])
		return (0);
	else if (argc == 2)
	{
		temp = ft_split(argv[1], ' ');
		if (!transform_into_list(&stack_a, temp))
		{
			free_entire_list(&stack_a);
			return (free_board(temp));
		}
		free_board(temp);
	}
	else
	{
		if (!transform_into_list(&stack_a, (argv + 1)))
			return (free_entire_list(&stack_a));
	}
	count_stack_length(&stack_a);
	free_entire_list(&stack_a);
	return (0);
}
