/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_to_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:38:10 by agaladi           #+#    #+#             */
/*   Updated: 2024/04/06 03:08:07 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_to_top(t_stack **stack, int content)
{
	int		target_position;
	int		stack_length;
	int		loop_rep;

	target_position = find_position(stack, content);
	loop_rep = target_position - 1;
	stack_length = list_len(stack);
	if (stack_length == 1)
		return ;
	while (loop_rep)
	{
		if ((*stack)->content == content)
			break;
		if (lst_last(stack)->content == content)
		{
			reverse_rotate_a(stack);
			break;
		}
		if (target_position <= (stack_length / 2))	
			rotate_a(stack);
		if (target_position == ((stack_length / 2) + 1))
			rotate_a(stack);
		else if (target_position > (stack_length / 2))
		{
			reverse_rotate_a(stack);
			if (lst_last(stack)->content == content)
			{
				reverse_rotate_a(stack);
				break;
			}
		}
		loop_rep--;
	}
}
