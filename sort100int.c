/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort100int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:39:33 by agaladi           #+#    #+#             */
/*   Updated: 2024/06/04 01:13:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort100int(t_stack **stack_a, t_stack **stack_b)
{
    // int max;
    int x;
    int i;

    (1 && (x = 16, i = 0));
    while (*stack_a)
    {
        if ((*stack_a)->sorted_index <= i)
        {
            push_b(stack_a, stack_b);
            i++;
        }
        else if ((*stack_a)->sorted_index <= i + x)
        {
            push_b(stack_a, stack_b);
            rotate_b(stack_b);
            i++;
        }
        else
            rotate_a(stack_a);
    }
    while (*stack_b)
    {
        // max = find_position(stack_b, max_content(stack_b));
        if ((*stack_b)->sorted_index == list_len(stack_b))
            push_a(stack_a, stack_b);
        else if ((*stack_b)->sorted_index < (list_len(stack_b) / 2))
        {
            // while (max-- > 0)
            rotate_b(stack_b);
        }
        else
        {
            // while (max++ < list_len(stack_b))
            reverse_rotate_b(stack_b);
        }
    }
}
