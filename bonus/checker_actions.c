/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 03:17:33 by agaladi           #+#    #+#             */
/*   Updated: 2024/06/20 05:23:43 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	checker_swap(t_stack *stack)
{
	t_stack	*current;
	int		temp1;
	int		temp2;

	if (!stack)
		return ;
	current = stack;
	temp1 = current->content;
	temp2 = current->sorted_index;
	current->content = current->next->content;
	current->sorted_index = current->next->sorted_index;
	current->next->content = temp1;
	current->next->sorted_index = temp2;
}

static t_stack	*get_prev_next(t_stack *stack)
{
	t_stack	*output;

	if (!stack)
		return (0);
	output = stack;
	while (output->next->next)
		output = output->next;
	return (output);
}

void	checker_push(t_stack **from, t_stack **to)
{
	t_stack	*head;

	if (!from || !(*from) || !to)
		return ;
	head = (*from)->next;
	ft_lstadd_front(to, (*from));
	(*from) = head;
}

void	checker_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	last = lst_last(stack);
	second->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	*stack = second;
}

void	checker_reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*prev_next;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	last = lst_last(stack);
	prev_next = get_prev_next(*stack);
	*stack = last;
	last->next = tmp;
	prev_next->next = NULL;
}