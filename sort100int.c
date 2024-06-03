/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort100int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:39:33 by agaladi           #+#    #+#             */
/*   Updated: 2024/06/03 12:03:03 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort100int(t_stack **stack_a, t_stack **stack_b)
{
    // int     max;
    int     x;
    int     i;

    (1 && (x = 16, i = 0));
    printf("\n%d\n", (*stack_a)->next->sorted_index);
    while (*stack_a)
    {
        printf("here 1\n");
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
    // while (*stack_b)
    // {
    //     printf("here 2\n");
    //     max = find_position(stack_b, max_content(stack_b));
    //     if ((*stack_b)->content == max_content(stack_b))
    //         push_a(stack_a, stack_b);
    //     else if (max < (list_len(stack_b) / 2))
    //     {
    //         while (max-- > 0)
    //             rotate_b(stack_b);
    //     }
    //     else if (max >= (list_len(stack_b) / 2))
    //     {
    //         while (max++ < list_len(stack_b))
    //             reverse_rotate_b(stack_b);
    //     }
    // }
}
