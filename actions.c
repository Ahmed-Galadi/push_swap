/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:39:16 by agaladi           #+#    #+#             */
/*   Updated: 2024/06/09 02:01:29 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char name)
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
	if (name == 'a')
		ft_putstr("sa\n");
	else
		ft_putstr("sb\n");
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

void	push(t_stack **from, t_stack **to, char name)
{
	t_stack	*head;

	if (!from || !(*from) || !to)
		return ;
	head = (*from)->next;
	ft_lstadd_front(to, (*from));
	(*from) = head;
	if (name == 'a')
		ft_putstr("pa\n");
	else if (name == 'b')
		ft_putstr("pb\n");
}

void	rotate(t_stack **stack, char name)
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
	if (name == 'a')
		ft_putstr("ra\n");
	else
		ft_putstr("rb\n");
}

void	reverse_rotate(t_stack **stack, char name)
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
	if (name == 'a')
		ft_putstr("rra\n");
	else
		ft_putstr("rrb\n");
}
