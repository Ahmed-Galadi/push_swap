/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:39:16 by agaladi           #+#    #+#             */
/*   Updated: 2024/03/25 04:08:43 by agaladi          ###   ########.fr       */
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

void	rotate_a(t_stack *stack_a)
{
	t_stack	*current;
	int		temp;

	current = stack_a;
	temp = current->content;
	current->content = lst_last(stack_a)->content;
	lst_last(stack_a)->content = temp;
}

void	rotate_b(t_stack *stack_b)
{
	t_stack	*current;
	int		temp;

	current = stack_b;
	temp = current->content;
	current->content = lst_last(stack_b)->content;
	lst_last(stack_b)->content = temp;
}