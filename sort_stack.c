/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:39:33 by agaladi           #+#    #+#             */
/*   Updated: 2024/06/06 05:59:13 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int num_top(t_stack *stack, int size)
{
    t_stack *head;
    int i;

    head = stack;
    i = 1;
    while (1)
    {
        if (stack->sorted_index == size)
            break;
        i++;
        stack = stack->next;
    }
    if (i <= list_len(&stack) / 2)
        return (1);
    return (0);
}

static void push_to_b(t_stack **stack_a, t_stack **stack_b)
{
    int i;
    int x;

    x = 16;
    if (list_len(stack_a) > 100)
        x = 34;
    i = 0;
    while (*stack_a)
    {
        if ((*stack_a)->sorted_index <= i)
        {
            push(stack_a, stack_b, 'b');
            i++;
        }
        else if ((*stack_a)->sorted_index <= i + x)
        {
            push(stack_a, stack_b, 'b');
            rotate(stack_b, 'b');
            i++;
        }
        else
            rotate(stack_a, 'a');
    }
}

static void push_to_a(t_stack **stack_a, t_stack **stack_b)
{
    int size;

    size = list_len(stack_b);
    while (*stack_b)
    {
        if ((*stack_b)->sorted_index == size)
        {
            push(stack_b, stack_a, 'a');
            size--;
        }
        else if (num_top(*stack_b, size) == 1)
            rotate(stack_b, 'b');
        else
            reverse_rotate(stack_b, 'b');
    }
}

void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
    push_to_b(stack_a, stack_b);
    push_to_a(stack_a, stack_b);
}