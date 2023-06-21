/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_indexes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 10:38:49 by wremy             #+#    #+#             */
/*   Updated: 2023/05/07 10:38:50 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_node *head, t_node *current_node)
{
	t_node	*other_node;
	int		index;

	index = 0;
	other_node = head;
	while (other_node != NULL)
	{
		if (other_node->value < current_node->value)
			index++;
		other_node = other_node->next;
	}
	return (index);
}

void	set_indexes(t_node *head)
{
	t_node	*current_node;
	int		index;

	current_node = head;
	while (current_node != NULL)
	{
		current_node->index = get_index(head, current_node);
		current_node = current_node->next;
	}
}
