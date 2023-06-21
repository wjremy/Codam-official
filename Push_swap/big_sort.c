/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:05:04 by wremy             #+#    #+#             */
/*   Updated: 2023/05/13 22:40:02 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rotate up as many times as target_position. Then push to b.

int	get_stack_size(t_node *stack)
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

int	get_highest_value(t_node *stack)
{
	int	max;
	t_node	*node;

	node = stack;
	max = node->value;
	while (node != NULL)
	{
		if (node->value > max)
			max = node->value;
		node = node->next;
	}
	return (max);
}

int	get_position_value(t_node *stack_b, int value)
{
	int	i;
	t_node *node;

	node = stack_b;
	i = 0;
	while (node->value != value)
	{
		node = node->next;
		i++;
	}
	return (i);
}

int	get_last_value(t_node *stack)
{
	t_node *node;
	
	node = stack;
	while (node->next != NULL)
		node=node->next;
	return(node->value);
}

int	get_moves(t_node *stack, int target_value)
{
	t_node* node;
	int		moves;
	int		last_value;

	last_value = get_last_value(stack);
	moves = 0;
	node = stack;
	while (node != NULL)
	{
		if (moves == 0)
		{
			if (target_value > node->value && target_value < last_value)
				return (moves);
		}
		else if (target_value > node->value && target_value < node->prev->value)
			return (moves);
		moves++;
		node = node->next;
	}
	return (moves);
}

void	do_cheapest_moves(int stack_size, int moves, t_node **stack_a, t_node **stack_b)
{
	char	*command;

	if (moves < stack_size / 2)
		command = "rb";
	else
	{
		moves = stack_size - moves;
		command = "rrb";
	}
	while (moves)
	{
		execute_command(stack_a, stack_b, command);
		moves--;
	}
	execute_command(stack_a, stack_b, "pb");
}

void	big_sort(t_node **stack_a, t_node **stack_b)
{
	int	target_value;
	int stack_value;
	int min;
	int max;
	int	moves;

	target_value = (*stack_a)->value;
	stack_value = (*stack_b)->value;
	min = get_lowest_value(*stack_b);
	max = get_highest_value(*stack_b);
	if (target_value < min)
		moves = get_position_value(*stack_b, min) + 1;
	else if (target_value > max)
		moves = get_position_value(*stack_b, max);
	else
		moves = get_moves(*stack_b, target_value);
	do_cheapest_moves(get_stack_size(*stack_b), moves, stack_a, stack_b);
}