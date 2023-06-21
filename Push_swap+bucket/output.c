/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:56:46 by wremy             #+#    #+#             */
/*   Updated: 2023/05/07 21:33:35 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_linked_list(t_node *head)
{
	t_node	*current;

	current = head;
	while (current != NULL)
	{
		ft_printf("%d, %d\n", current->value, current->index);
		current = current->next;
	}
}

void print_stacks(char* msg, t_node* stack_a, t_node* stack_b) {
    printf("\n%s\n", msg);
	while (stack_a != NULL || stack_b != NULL) {
        if (stack_a != NULL) {
            printf("%d | ", stack_a->value);
            stack_a = stack_a->next;
        } else {
            printf("  | ");
        }
        if (stack_b != NULL) {
            printf("%d", stack_b->value);
            stack_b = stack_b->next;
        } else {
			printf("  ");
		}
        printf("\n");
    }
	printf("\n");
}