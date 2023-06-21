/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wremy <wremy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:28:38 by wremy             #+#    #+#             */
/*   Updated: 2023/05/07 23:03:39 by wremy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

t_node	*create_node(int value);
t_node	*create_and_append_node(t_node **head, t_node **tail, int value);
t_node	*create_linked_list(int argc, char *argv[]);

int		ft_isnumeric(char *c);
int		validate_input(int argc, char *argv[]);
void	print_linked_list(t_node *head);
void	execute_command(t_node **stack_a, t_node **stack_b, char *command);
void	set_indexes(t_node *head);
void	big_sort(t_node **stack_a, t_node **stack_b);
void	small_sort_a(t_node **stack_a, t_node **stack_b, int argc);
void	small_sort_b(t_node **stack_a, t_node **stack_b, int argc);
void print_stacks(char* msg, t_node* stack_a, t_node* stack_b);
int	get_lowest_value(t_node *stack);

#endif