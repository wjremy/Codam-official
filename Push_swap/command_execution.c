/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 18:02:39 by wremy             #+#    #+#             */
/*   Updated: 2023/05/15 16:07:38 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*second_node;
	t_node	*third_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	second_node = (*stack)->next;
	third_node = second_node->next;
	second_node->prev = NULL;
	second_node->next = *stack;
	(*stack)->next = third_node;
	(*stack)->prev = second_node;
	third_node->prev = *stack;
	*stack = second_node;
}

void	push(t_node **first_stack, t_node **second_stack)
{
	t_node	*first_node;

	if (*first_stack == NULL)
		return ;
	first_node = *first_stack;
	*first_stack = (*first_stack)->next;
	if (*first_stack)
		(*first_stack)->prev = NULL;
	first_node->next = *second_stack;
	if (*second_stack)
		(*second_stack)->prev = first_node;
	*second_stack = first_node;
}

void	rotate(t_node **stack)
{
	t_node	*first_node;
	t_node	*last_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first_node = *stack;
	last_node = *stack;
	while (last_node->next != NULL)
		last_node = last_node->next;
	*stack = first_node->next;
	(*stack)->prev = NULL;
	first_node->next = NULL;
	first_node->prev = last_node;
	last_node->next = first_node;
}

void	reversed_rotate(t_node **stack)
{
	t_node	*first_node;
	t_node	*one_before_last_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first_node = *stack;
	while ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
	}
	one_before_last_node = (*stack)->prev;
	//print_linked_list(one_before_last_node);
	one_before_last_node->next = NULL;
	(*stack)->prev = NULL;
	(*stack)->next = first_node;
	first_node->prev = *stack;
}

void	execute_command(t_node **stack_a, t_node **stack_b, char *command)
{
	if (!ft_strncmp(command, "sa", 3) || !ft_strncmp(command, "ss", 3))
		swap(stack_a);
	if (!ft_strncmp(command, "sb", 3) || !ft_strncmp(command, "ss", 3))
		swap(stack_b);
	if (!ft_strncmp(command, "pa", 3))
		push(stack_b, stack_a);
	if (!ft_strncmp(command, "pb", 3))
		push(stack_a, stack_b);
	if (!ft_strncmp(command, "ra", 3) || !ft_strncmp(command, "rr", 3))
		rotate(stack_a);
	if (!ft_strncmp(command, "rb", 3) || !ft_strncmp(command, "rr", 3))
		rotate(stack_b);
	if (!ft_strncmp(command, "rra", 3) || !ft_strncmp(command, "rrr", 3))
		reversed_rotate(stack_a);
	if (!ft_strncmp(command, "rrb", 3) || !ft_strncmp(command, "rrr", 3))
		reversed_rotate(stack_b);
	ft_printf("%s\n", command);
	static int counter = 0;
	counter++;
	printf("counter = %i", counter);
}
