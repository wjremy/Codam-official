/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:42:40 by wremy             #+#    #+#             */
/*   Updated: 2023/05/15 16:28:08 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_node	*stack_a;
	t_node	*stack_b;

	i = 0;
	if (!validate_input(argc, argv))
		return (-1);
	stack_a = create_linked_list(argc, argv);
	if (stack_a == NULL)
		return (-1);
	stack_b = NULL;
	set_indexes(stack_a);
	// execute_command(&stack_a, &stack_b, "pb");
	// execute_command(&stack_a, &stack_b, "pb");
	// execute_command(&stack_a, &stack_b, "pb");
	// small_sort_b(&stack_a, &stack_b, argc);
	//execute_command(&stack_a, &stack_b, "rra");
	// execute_command(&stack_a, &stack_b, "pb");
	//execute_command(&stack_a, &stack_b, "pb");
		print_stacks("start", stack_a, stack_b);
		execute_command(&stack_a, &stack_b, "pb");
		execute_command(&stack_a, &stack_b, "pb");
		execute_command(&stack_a, &stack_b, "pb");
		print_stacks("after push", stack_a, stack_b);
		// 		execute_command(&stack_a, &stack_b, "sb");
		// print_stacks("after", stack_a, stack_b);
		
		// 		execute_command(&stack_a, &stack_b, "rrb");
		// print_stacks("after", stack_a, stack_b);
		// execute_command(&stack_a, &stack_b, "pb");
		// print_stacks("after", stack_a, stack_b);
		small_sort_b(&stack_a, &stack_b, 4);
		print_stacks("after simple sort", stack_a, stack_b);
		// execute_command(&stack_a, &stack_b, "rrb");
		//print_stacks("after", stack_a, stack_b);
		while (i + 3 < argc - 1)
		{
			big_sort(&stack_a, &stack_b);
			print_stacks("after sort", stack_a, stack_b);
			i++;
		}
		// print_stacks("after 3rd sort", stack_a, stack_b);
		// 		big_sort(&stack_a, &stack_b);
		// print_stacks("after 3rd sort", stack_a, stack_b);
		// 		big_sort(&stack_a, &stack_b);
		// print_stacks("after 3rd sort", stack_a, stack_b);
	//set_target_position(&stack_a, &stack_b);
	//set_target_position(&stack_a, &stack_b);
	//set_target_position(&stack_a, &stack_b);
	//set_target_position(&stack_a, &stack_b);
	// set_target_position(&stack_a, &stack_b);
	// set_target_position(&stack_a, &stack_b);
	// set_target_position(&stack_a, &stack_b);
	//set_target_position(&stack_a, &stack_b);
	// set_target_position(&stack_a, &stack_b);
	//set_target_position(&stack_a, &stack_b);
	//set_target_position(&stack_a, &stack_b);
	//set_target_position(&stack_a, &stack_b);
	//set_target_position(&stack_a, &stack_b);

	// t_node *node = stack_a;
	// printf("%i", node->value);
	// print_linked_list(node);
	// execute_command(&stack_a, &stack_b, "ra");
	// printf("%i", node->value);
	// print_linked_list(node);
	//execute_command(&stack_a, &stack_b, "sb");
	// print_linked_list(stack_b);
}
