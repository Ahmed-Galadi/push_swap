/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:39:16 by agaladi           #+#    #+#             */
/*   Updated: 2024/03/27 22:57:45 by agaladi          ###   ########.fr       */
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

void	rotate_a(t_stack **stack_a)
{
	t_stack *current;
	int		tmp;

	current = *stack_a;
	tmp = current->content;
	lst_add_last(&current, tmp);
	*stack_a = current->next;
	free(current);
}

void	rotate_b(t_stack **stack_b)
{
	t_stack *current;
	int		tmp;

	current = *stack_b;
	tmp = current->content;
	lst_add_last(&current, tmp);
	*stack_b = current->next;
	free(current);
}

void	reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*last_node;
	int		tmp;

	last_node = lst_last(stack_a);
	tmp = last_node->content;
	last_node->prev->next = NULL;
	free(last_node);
	lst_add_first(stack_a, tmp);
}

void	reverse_rotate_b(t_stack **stack_b)
{
	t_stack	*last_node;
	int		tmp;

	last_node = lst_last(stack_b);
	tmp = last_node->content;
	last_node->prev->next = NULL;
	free(last_node);
	lst_add_first(stack_b, tmp);
}