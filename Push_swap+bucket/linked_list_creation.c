/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_creation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:46:58 by wremy             #+#    #+#             */
/*   Updated: 2023/04/30 17:51:24 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}


t_node	*create_and_append_node(t_node **head, t_node **tail, int value)
{
	t_node	*node;

	node = create_node(value);
	if (node == NULL)
		return (NULL);
	if (*head == NULL)
	{
		*head = node;
		*tail = node;
	}
	else
	{
		(*tail)->next = node;
		node->prev = *tail;
		*tail = node;
	}
	return (node);
}

t_node	*create_linked_list(int argc, char *argv[])
{
	int		i;
	int		value;
	t_node	*head;
	t_node	*tail;

	i = 1;
	head = NULL;
	tail = NULL;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		if (create_and_append_node(&head, &tail, value) == NULL)
			return (NULL);
		i++;
	}
	return (head);
}