/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:39:16 by agaladi           #+#    #+#             */
/*   Updated: 2024/04/02 06:40:16 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack_a)
{
	t_stack	*current;
	int		temp;

	if (!stack_a)
		return ;
	current = stack_a;
	temp = current->content;
	current->content = current->next->content;
	current->next->content = temp;
	ft_putstr("\nsa");
}

void	swap_b(t_stack *stack_b)
{
	t_stack	*current;
	int		temp;

	if (!stack_b)
		return ;
	current = stack_b;
	temp = current->content;
	current->content = current->next->content;
	current->next->content = temp;
	ft_putstr("\nsb");
}

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_putstr("\nss");
}

void rotate_a(t_stack **stack_a)
{
	t_stack *last_node;
	t_stack *current;

	if (!*stack_a)
		return;
	last_node = lst_last(stack_a);
	current = *stack_a;
	*stack_a = current->next;
	current->next->prev = NULL;
	current->prev = last_node;
	current->next = NULL;
	last_node->next = current;
	ft_putstr("\nra");
}

void rotate_b(t_stack **stack_b)
{
	t_stack *last_node;
	t_stack *current;

	if (!*stack_b)
		return;
	last_node = lst_last(stack_b);
	current = *stack_b;
	*stack_b = current->next;
	current->next->prev = NULL;
	current->prev = last_node;
	current->next = NULL;
	last_node->next = current;
	ft_putstr("\nrb");
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_putstr("\nrr");
}

void reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*last_node;
	t_stack	*current;

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
	ft_putstr("\nrra");
}

void reverse_rotate_b(t_stack **stack_b)
{
	t_stack	*last_node;
	t_stack	*current;

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
	ft_putstr("\nrrb");
}

void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	ft_putstr("\nrrr");
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;
	t_stack	*current_b;

	current_a = *stack_a;
	current_b = *stack_b;
	if (!current_b)
		return ;
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
	ft_putstr("\npa");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;
	t_stack	*current_b;

	current_a = *stack_a;
	current_b = *stack_b;
	if (!current_a)
		return ;
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
	ft_putstr("\npb");
}
