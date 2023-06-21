/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buckets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:03:03 by wremy             #+#    #+#             */
/*   Updated: 2023/05/15 20:34:00 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves_if_rotate_up(t_node *stack, int bucketsize, int bucket)
{
	int	moves;

	moves = 0;
	while (stack->index >= bucketsize * bucket && stack != NULL)
	{
		stack = stack->next;
		moves++;
	}
	return (moves);
}

int	moves_if_rotate_down(t_node *stack, int bucketsize, int bucket)
{
	int	moves;

	moves = 0;
	while (stack->index >= bucketsize * bucket && stack != NULL)
	{
		if (moves == 0)
			stack = get_last_node(stack);
		else
			stack = stack->prev;
		moves++;
	}
	return (moves);
}

int	values_left_for_bucket(int bucket, int bucketsize, t_node *stack)
{
	while (stack != NULL)
	{
		if (stack->index < bucketsize * bucket)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	put_target_in_bucket(t_node **stack_a, t_node **stack_b, int bucketsize, int bucket)
{
	int	moves_to_rotate_up;
	int	moves_to_rotate_down;
	int	moves;

	moves_to_rotate_up = moves_if_rotate_up(*stack_a, bucketsize, bucket);
	moves_to_rotate_down = moves_if_rotate_down(*stack_a, bucketsize, bucket);
	moves = 0;
	if (moves_to_rotate_up < moves_to_rotate_down)
	{
		while (moves < moves_to_rotate_up)
		{
			execute_command(stack_a, stack_b, "ra");
			moves++;
		}
	}
	else
	{
		while (moves < moves_to_rotate_down)
		{
			execute_command(stack_a, stack_b, "rra");
			moves++;
		}
	}
	execute_command(stack_a, stack_b, "pb");
}

void	put_a_into_buckets_in_b(t_node **stack_a, t_node **stack_b, int argc)
{
	int	bucket;
	int	buckets;
	int	bucketsize;

	bucket = 1;
	buckets = 9;
	bucketsize = (argc - 1) / buckets;
	while (bucket <= buckets)
	{
		while (values_left_for_bucket(bucket, bucketsize, *stack_a)
			&& get_stack_size(*stack_a) != 3)
			put_target_in_bucket(stack_a, stack_b, bucketsize, bucket);
		bucket++;
	}
	small_sort_a(stack_a, stack_b, 4);
}
