/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors_Check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:56:15 by bproton           #+#    #+#             */
/*   Updated: 2024/02/28 11:39:58 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_errors_in_str(char *str)
{
	int	i;

	i = 0;
	if ((str[0] != '-' && str[0] != '+') && (str[0] < '0' || str[0] > '9'))
	{
		write (1, "Error\n", 6);
		return (0);
	}
	if ((str[0] == '-' || str[0] == '+') && (str[1] < '0' || str[1] > '9'))
	{
		write (1, "Error\n", 6);
		return (0);
	}
	else
	{
		while (str[++i] != '\0')
		{
			if (str[i] < '0' || str[i] > '9')
			{
				write (1, "Error\n", 6);
				return (0);
			}
		}
	}
	return (1);
}

int	check_same_numbers(long num, t_stack *stack_a)
{
	if (stack_a != NULL)
	{
		while (stack_a)
		{
			if (num == stack_a->value)
			{
				write (1, "Error\n", 6);
				return (0);
			}
			stack_a = stack_a->next;
		}
	}
	return (1);
}

int	free_board(char **temp)
{
	int	i;

	i = 0;
	while (temp[i] != NULL)
	{
		free(temp[i]);
		i++;
	}
	free(temp);
	return (0);
}

int	is_sorted(t_stack *stack_a)
{
	t_stack	*temp;

	temp = stack_a;
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}