/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:39:16 by agaladi           #+#    #+#             */
/*   Updated: 2024/06/05 23:43:48 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_stack *stack_a)
{
	t_stack *current;
	int temp1;
	int temp2;

	if (!stack_a)
		return;
	current = stack_a;
	temp1 = current->content;
	temp2 = current->sorted_index;
	current->content = current->next->content;
	current->sorted_index = current->next->sorted_index;
	current->next->content = temp1;
	current->next->sorted_index = temp2;
	ft_putstr("sa\n");
}

void swap_b(t_stack *stack_b)
{
	t_stack *current;
	int temp1;
	int temp2;

	if (!stack_b)
		return;
	current = stack_b;
	temp1 = current->content;
	temp2 = current->sorted_index;
	current->content = current->next->content;
	current->sorted_index = current->next->sorted_index;
	current->next->content = temp1;
	current->next->sorted_index = temp2;
	ft_putstr("sb\n");
}

void swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_putstr("ss\n");
}

void rotate_a(t_stack **stack_a)
{
	t_stack *last_node;
	t_stack *second_last;
	t_stack *head;
	t_stack *second;

	if (!*stack_a)
		return;
	last_node = lst_last(stack_a);
	head = *stack_a;
	second = head->next;
	second_last = last_node->prev;
	*stack_a = last_node;
	(*stack_a)->next = second;
	(*stack_a)->prev = NULL;
	head->prev = second_last;
	head->next = NULL;
	ft_putstr("ra\n");
}

void rotate_b(t_stack **stack_b)
{
	t_stack *last_node;
	t_stack *second_last;
	t_stack *head;
	t_stack *second;

	if (!*stack_b)
		return;
	last_node = lst_last(stack_b);
	head = *stack_b;
	second = head->next;
	second_last = last_node->prev;
	*stack_b = last_node;
	(*stack_b)->next = second;
	(*stack_b)->prev = NULL;
	head->prev = second_last;
	head->next = NULL;
	ft_putstr("rb\n");
}

void rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_putstr("rr\n");
}

void reverse_rotate_a(t_stack **stack_a)
{
	t_stack *last_node;
	t_stack *current;

	if (!*stack_a)
		return;
	last_node = lst_last(stack_a);
	current = *stack_a;
	current->prev = last_node;
	last_node->next = current;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	current = current->prev;
	*stack_a = current;
	ft_putstr("rra\n");
}

void reverse_rotate_b(t_stack **stack_b)
{
	t_stack *last_node;
	t_stack *current;

	if (!*stack_b)
		return;
	last_node = lst_last(stack_b);
	current = *stack_b;
	current->prev = last_node;
	last_node->next = current;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	current = current->prev;
	*stack_b = current;
	ft_putstr("rrb\n");
}

void reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	ft_putstr("rrr\n");
}

void push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *current_a;
	t_stack *current_b;

	current_a = *stack_a;
	current_b = *stack_b;
	if (!current_b)
		return;
	if (!current_a)
	{
		current_a = current_b;
		current_b = current_b->next;
		current_b->prev = NULL;
		current_a->next = NULL;
		*stack_a = current_a;
		*stack_b = current_b;
	}
	else
	{
		*stack_b = current_b->next;
		current_b->next = current_a;
		current_a->prev = current_b;
		*stack_a = current_b;
	}
	ft_putstr("pa\n");
}

void push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *current_a;
	t_stack *current_b;

	current_a = *stack_a;
	current_b = *stack_b;
	if (!current_a)
		return;
	if (!current_b)
	{
		current_b = current_a;
		current_a = current_a->next;
		current_a->prev = NULL;
		current_b->next = NULL;
		*stack_a = current_a;
		*stack_b = current_b;
	}
	else
	{
		*stack_a = current_a->next;
		current_a->next = current_b;
		current_b->prev = current_a;
		*stack_b = current_a;
	}
	ft_putstr("pb\n");
}
