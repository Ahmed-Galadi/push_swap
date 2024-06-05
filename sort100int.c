/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort100int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:39:33 by agaladi           #+#    #+#             */
/*   Updated: 2024/06/05 01:07:52 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_lstpenultimate(t_stack *lst)
{
    t_stack *tmp;

    if (!lst)
        return (0);
    tmp = lst;
    while (tmp->next->next)
        tmp = tmp->next;
    return (tmp);
}

void ft_r_rotate(t_stack **stack, char s)
{
    t_stack *tmp;
    t_stack *last;
    t_stack *penultimate;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    tmp = *stack;

    // Find the last node
    last = *stack;
    while (last->next)
    {
        last = last->next;
    }

    // Find the penultimate node
    penultimate = ft_lstpenultimate(*stack);

    // Perform the rotation
    *stack = last;
    last->next = tmp;
    penultimate->next = NULL;

    if (s == 'A' || s == 'a')
        printf("rra\n");
    else
        printf("rrb\n");
}

void ft_rotate(t_stack **list, char stack)
{
    if (!list || !*list || !(*list)->next)
        return; // Nothing to rotate if list is empty or has only one node

    t_stack *first = *list;
    t_stack *second = (*list)->next;
    t_stack *last = *list;

    while (last->next)
    {
        last = last->next;
    }

    second->prev = NULL;
    last->next = first;
    first->prev = last;
    first->next = NULL;
    *list = second;
    if (stack == 'A' || stack == 'a')
        printf("ra\n");
    else
        printf("rb\n");
}

void ft_lstadd_front(t_stack **lst, t_stack *new)
{
    if (!new || !lst)
        return;
    new->next = *lst;
    *lst = new;
}

void push(t_stack **from, t_stack **to, char stack)
{
    t_stack *head;

    if (!from || !(*from) || !to)
        return;
    head = (*from)->next;
    ft_lstadd_front(to, (*from));
    (*from) = head;
    if (stack == 'a' || stack == 'A')
        printf("pa\n");
    else if (stack == 'b' || stack == 'B')
        printf("pb\n");
}

void sort100int(t_stack **stack_a, t_stack **stack_b)
{
    // int max;
    int x;
    int i;

    (1 && (x = 16, i = 0));

    // int len = list_len(stack_b);
    // print_stack(*stack_b, "b");
    // print_stack(*stack_a, "a");
    // printf("%d %d\n", len, len2);
    int s = list_len(stack_a);
    while (s > 0)
    {
        if ((*stack_a)->sorted_index <= i)
        {
            push(stack_a, stack_b, 'b');
            i++;
            s--;
        }
        else if ((*stack_a)->sorted_index <= i + x)
        {
            push(stack_a, stack_b, 'b');
            ft_rotate(stack_b, 'b');
            i++;
            s--;
        }
        else
            ft_rotate(stack_a, 'a');
    }
    // push_b(stack_a, stack_b);
    // len = list_len(stack_b);
    // int len2 = list_len(stack_a);
    // len2 = list_len(stack_a);
    // print_stack(*stack_b, "b");
    // print_stack(*stack_a, "a");
    // printf("%d %d: i \n", len, len2);
    // index_stack(*stack_b);
    // print_stack(*stack_b, "b");
    // exit(0);
    s = list_len(stack_b);
    // printf("size: %d\n", s);
    while (s > 0)
    {
        int max = max_content(stack_b);
        if ((*stack_b)->content == max)
        {
            push_a(stack_b, stack_a);
            s--;
        }
        else
            ft_rotate(stack_b, 'b');
        // printf("max: %d\n", max);
        // printf("len: %d\nint: %d\n", i ,(*stack_b)->sorted_index);
        // int max = find_position(stack_b, max_content(stack_b));
        // if ((i = find_position(stack_b, (*stack_b)->content)) == max)
        // {
        //     push_a(stack_a, stack_b);
        // }
        // else if (i < (list_len(stack_b) / 2))
        // {
        //     while (max-- > 0)
        // 		rotate_b(stack_b);
        // }
        // else
        // {
        //     while (max++ < list_len(stack_b))
        // 		reverse_rotate_b(stack_b);
        // }
    }
}
