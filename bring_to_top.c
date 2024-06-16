/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_to_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:38:10 by agaladi           #+#    #+#             */
/*   Updated: 2024/06/16 04:33:07 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_to_top(t_stack **stack, int content)
{
	int		target_position;

	target_position = find_position(stack, content);
	if (target_position <= list_len(stack) / 2)
	{
		while ((*stack)->content != content)
			rotate(stack, 'a');
	}
	else
		while ((*stack)->content != content)
			reverse_rotate(stack, 'a');
}
