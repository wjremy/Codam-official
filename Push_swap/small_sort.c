/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:55:41 by wremy             #+#    #+#             */
/*   Updated: 2023/05/07 21:08:39 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_highest_value(t_node *stack, int value)
{
	while (stack != NULL)
	{
		if (stack->value > value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_lowest_value(t_node *stack, int value)
{
	while (stack != NULL)
	{
		if (stack->value < value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_three_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*node;
	int		i;

	node = *stack_b;
	i = 0;
	while (node != NULL)
	{
		if (is_lowest_value(*stack_b, node->value))
		{
			if (i == 0)
				execute_command(stack_a, stack_b, "rb");
			if (i == 1)
				execute_command(stack_a, stack_b, "rrb");
			break ;
		}
		i++;
		node = node->next;
	}
	if ((*stack_b)->value < (*stack_b)->next->value)
		execute_command(stack_a, stack_b, "sb");
}

void	sort_three_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*node;
	int		i;

	node = *stack_a;
	i = 0;
	while (node != NULL)
	{
		if (is_highest_value(*stack_a, node->value))
		{
			if (i == 0)
				execute_command(stack_a, stack_b, "ra");
			if (i == 1)
				execute_command(stack_a, stack_b, "rra");
			break ;
		}
		i++;
		node = node->next;
	}
	if ((*stack_a)->value > (*stack_a)->next->value)
		execute_command(stack_a, stack_b, "sa");
}

void	small_sort_a(t_node **stack_a, t_node **stack_b,
					int argc)
{
	if (argc == 3)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			execute_command(stack_a, stack_b, "ra");
	}
	if (argc == 4)
		sort_three_a(stack_a, stack_b);
}

void	small_sort_b(t_node **stack_a, t_node **stack_b,
					int argc)
{
	if (argc == 3)
	{
		if ((*stack_b)->value < (*stack_b)->next->value)
			execute_command(stack_a, stack_b, "rb");
	}
	if (argc == 4)
		sort_three_b(stack_a, stack_b);
}