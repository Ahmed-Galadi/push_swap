/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort100int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:39:33 by agaladi           #+#    #+#             */
/*   Updated: 2024/06/02 19:08:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort100int(t_stack **stack_a, t_stack **stack_b)
{
    int     size;
    int     max;
    int     x;
    int     i;

    (1 && (size = list_len(stack_a), x = 16, i = 0));
    while (i < size)
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
    max = find_position(stack_b, max_content(stack_b));
    if (max < (size / 2))
    {
        while (max-- > 0)
            rotate_b(stack_b);
    }
    else if (max >= (size / 2))
    {
        while (max++ < size)
            reverse_rotate_b(stack_b);
    }
    while (*stack_b)
        push_a(stack_a, stack_b);
}
