/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_nbrs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 04:37:34 by agaladi           #+#    #+#             */
/*   Updated: 2024/03/31 05:00:30 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_case_1(int first, int second, int third)
{
	if (first > second && first < third)
	{
		if (second < third)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

//				   3		  2		     1
// case_2 :		  big      middle      little
static int is_case_2(int first, int second, int third)
{
	if (first > second && first > third)
	{
		if (second > third)
			return (1);
		else 
			return (0);
	}
	else 
		return (0);
}

//				   3		   1		     2
// case_3 :		  big        little        middle
static int is_case_3(int first, int second, int third)
{
	if (first > second && first > third)
	{
		if (second < third)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

//                   1         3           2  
// case_4 :		  little      big       middle
static int is_case_4(int first, int second, int third)
{
	if (first < second && first < third)
	{
		if (second > third)
			return (1);
		else
			return (0);
	}
	else 
		return (0);
}

void	sort_three_nbrs(t_stack **stack_a)
{
	t_stack	*stack;
	int		first;
	int		second;
	int		third;

	stack = *stack_a;
	first = stack->content;
	second = stack->next->content;
	third = stack->next->next->content;
	if (is_case_1(first, second, third))
		swap_a(*stack_a);
	else if (is_case_2(first, second, third))
	{
		swap_a(*stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (is_case_3(first, second, third))
		rotate_a(stack_a);
	else if (is_case_4(first, second, third))
	{
		swap_a(*stack_a);
		rotate_a(stack_a);
	}
	else
		reverse_rotate_a(stack_a);
}
