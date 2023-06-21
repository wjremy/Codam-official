/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:42:40 by wremy             #+#    #+#             */
/*   Updated: 2023/05/15 20:25:52 by wremy            ###   ########.fr       */
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
	if (argc < 4)
		small_sort_a(&stack_a, &stack_b, argc);
	put_a_into_buckets_in_b(&stack_a, &stack_b, argc);
	//print_stacks("start", stack_a, stack_b);
	big_sort(&stack_a, &stack_b, argc);
	//print_stacks("start", stack_a, stack_b);
}
