/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:39:16 by agaladi           #+#    #+#             */
/*   Updated: 2024/03/29 04:58:31 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack_a)
{
	t_stack	*current;
	int		temp;

	current = stack_a;
	temp = current->content;
	current->content = current->next->content;
	current->next->content = temp;
}

void	swap_b(t_stack *stack_b)
{
	t_stack	*current;
	int		temp;

	current = stack_b;
	temp = current->content;
	current->content = current->next->content;
	current->next->content = temp;
}

void rotate_a(t_stack **stack_a)
{
	t_stack *last_node;
	t_stack *current;

	last_node = lst_last(stack_a);
	current = *stack_a;
	*stack_a = current->next;
	current->next->prev = NULL;
	current->prev = last_node;
	current->next = NULL;
	last_node->next = current;
}

void rotate_b(t_stack **stack_b)
{
	t_stack *last_node;
	t_stack *current;

	last_node = lst_last(stack_b);
	current = *stack_b;
	*stack_b = current->next;
	current->next->prev = NULL;
	current->prev = last_node;
	current->next = NULL;
	last_node->next = current;
}

void reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*last_node;
	t_stack	*current;

	last_node = lst_last(stack_a);
	current = *stack_a;
	current->prev = last_node;
	last_node->next = current;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	current = current->prev;
	*stack_a = current;
	
}

void reverse_rotate_b(t_stack **stack_b)
{
	t_stack	*last_node;
	t_stack	*current;

	last_node = lst_last(stack_b);
	current = *stack_b;
	current->prev = last_node;
	last_node->next = current;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	current = current->prev;
	*stack_b = current;
}

void push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *current_a;
	t_stack *current_b;

	current_a = *stack_a;
	current_b = *stack_b;
	*stack_b = current_b->next;
	current_b->next = *stack_a;
	current_a->prev = current_b;
	*stack_a = current_a->prev;
}

void push_b(t_stack **stack_b, t_stack **stack_a)
{
	t_stack *current_a;
	t_stack *current_b;

	current_a = *stack_a;
	current_b = *stack_b;
	*stack_b = current_b->next;
	current_b->next = *stack_a;
	current_a->prev = current_b;
	*stack_a = current_a->prev;
}