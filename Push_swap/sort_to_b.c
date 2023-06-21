/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:05:04 by wremy             #+#    #+#             */
/*   Updated: 2023/05/07 22:11:30 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rotate up as many times as target_position. Then push to b.

int	size_stack(t_node *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	get_lowest_value(t_node *stack)
{
	int	min;
	t_node	*node;

	node = stack;
	min = node->value;
	while (node != NULL)
	{
		if (node->value < min)
			min = node->value;
		node = node->next;
	}
	return (min);
}

int	get_position_min(t_node *stack_b, int min_value)
{
	int	i;
	t_node *node;
	
	node = stack_b;
	i = 0;
	while (node->value != min_value)
	{
		node = node->next;
		i++;
	}
	return (i);
}

int	insert_in_b(t_node **stack_a, t_node **stack_b)
{
	int		target_position;
	t_node	*node;
	static int min_value;

	node = *stack_b;
	target_position = 0;
	min_value = get_lowest_value(*stack_b);
	if ((*stack_a)->value < min_value)
	{
		return(get_position_min(*stack_b, min_value) + 1);
		min_value = (*stack_a)->value;
	}
	while (node != NULL)
	{
		if (node->prev != NULL)
		{
		if ((*stack_a)->value > node->value && (*stack_a)->value < node->prev->value)
			return (target_position);
		}
		node = node -> next;
		target_position++;
	}
	return (target_position);
}

void	set_target_position(t_node **stack_a, t_node **stack_b)
{
	int	rotations;
	int	total_rotations;
	int size_stack_b;
	int reversed;

	reversed = 0;
	rotations = 0;
	total_rotations = insert_in_b(stack_a, stack_b);
	size_stack_b = size_stack(*stack_b);
	// if (total_rotations > 0.5 * size_stack_b)
	// 	total_rotations = size_stack_b - total_rotations;
	// 	reversed = 1;
	while (rotations < total_rotations)
	{
		// if (reversed)
		// 	execute_command(stack_a, stack_b, "rrb");
		// else
			execute_command(stack_a, stack_b, "rb");
		// printf("|");
		// print_linked_list(*stack_b);
		// printf("|");
		rotations++;
	}
	execute_command(stack_a, stack_b, "pb");
}