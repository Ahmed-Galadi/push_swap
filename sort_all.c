/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 03:09:37 by agaladi           #+#    #+#             */
/*   Updated: 2024/06/16 02:07:56 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_nbrs(t_stack **stack_a)
{
	t_stack	*current;

	current = *stack_a;
	if (current->content > current->next->content)
		swap(*stack_a, 'a');
}

void	sort_three_nbrs(t_stack **stack_a, t_stack **stack_b)
{
	int		min_nbr;

	min_nbr = lowest_content(stack_a);
	bring_to_top(stack_a, min_nbr);
	push(stack_a, stack_b, 'b');
	sort_two_nbrs(stack_a);
	push(stack_b, stack_a, 'a');
}

void	sort_four_nbrs(t_stack **stack_a, t_stack **stack_b)
{
	int		min_nbr;

	min_nbr = lowest_content(stack_a);
	bring_to_top(stack_a, min_nbr);
	push(stack_a, stack_b, 'b');
	sort_three_nbrs(stack_a, stack_b);
	push(stack_b, stack_a, 'a');
}

void	sort_five_nbrs(t_stack **stack_a, t_stack **stack_b)
{
	int		min_nbr;

	min_nbr = lowest_content(stack_a);
	bring_to_top(stack_a, min_nbr);
	push(stack_a, stack_b, 'b');
	sort_four_nbrs(stack_a, stack_b);
	push(stack_b, stack_a, 'a');
}

void	sort_all(t_stack **stack_a, t_stack **stack_b)
{
	int		stack_len;

	stack_len = list_len(stack_a);
	if (stack_len == 1)
		return ;
	if (stack_len == 2)
		sort_two_nbrs(stack_a);
	if (stack_len == 3)
		sort_three_nbrs(stack_a, stack_b);
	if (stack_len == 4)
		sort_four_nbrs(stack_a, stack_b);
	if (stack_len == 5)
		sort_five_nbrs(stack_a, stack_b);
	if (stack_len > 5)
		sort_stack(stack_a, stack_b);
}
