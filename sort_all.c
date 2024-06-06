/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 03:09:37 by agaladi           #+#    #+#             */
/*   Updated: 2024/06/06 01:54:20 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_two_nbrs(t_stack **stack_a)
{
	t_stack *stack;
	int first_nbr;
	int second_nbr;

	stack = *stack_a;
	first_nbr = stack->content;
	second_nbr = stack->next->content;
	if (first_nbr > second_nbr)
		swap_a(*stack_a);
}

void sort_three_nbrs(t_stack **stack_a)
{
	int min_nbr;

	min_nbr = lowest_content(stack_a);
	bring_to_top(stack_a, min_nbr);
	sort_two_nbrs(&((*stack_a)->next));
}

void sort_four_nbrs(t_stack **stack_a, t_stack **stack_b)
{
	int min_nbr;

	min_nbr = lowest_content(stack_a);
	bring_to_top(stack_a, min_nbr);
	push_b(stack_a, stack_b);
	sort_three_nbrs(stack_a);
	push_a(stack_a, stack_b);
}

void sort_five_nbrs(t_stack **stack_a, t_stack **stack_b)
{
	int min_nbr;

	min_nbr = lowest_content(stack_a);
	bring_to_top(stack_a, min_nbr);
	push_b(stack_a, stack_b);
	sort_four_nbrs(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

int num_top(t_stack *a, int count)
{
	t_stack *head;
	int i;

	head = a;
	i = 1;
	while (1)
	{
		if (a->sorted_index == count)
			break;
		i++;
		a = a->next;
	}
	if (i <= list_len(&a) / 2)
		return (1);
	return (0);
}
void ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!new || !lst)
		return;
	new->next = *lst;
	new->prev = NULL;
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
	last = *stack;
	while (last->next)
	{
		last = last->next;
	}
	penultimate = ft_lstpenultimate(*stack);
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

void push_to_a(t_stack **stack_A, t_stack **stack_B)
{
	int i;
	int x;

	x = 16;
	if (list_len(stack_A) > 100)
		x = 34;
	i = 0;
	while (*stack_A)
	{
		if ((*stack_A)->sorted_index <= i)
		{
			push(stack_A, stack_B, 'b');
			i++;
		}
		else if ((*stack_A)->sorted_index <= i + x)
		{

			push(stack_A, stack_B, 'b');
			ft_rotate(stack_B, 'b');

			i++;
		}
		else
			ft_rotate(stack_A, 'a');
	}
}

void sort_stack(t_stack **a, t_stack **b)
{
	int size;

	push_to_a(a, b);
	size = list_len(b);
	while (*b)
	{
		if ((*b)->sorted_index == size)
		{
			push(b, a, 'a');
			size--;
		}
		else if (num_top(*b, size) == 1)
			ft_rotate(b, 'b');
		else
			ft_r_rotate(b, 'b');
	}
}

void sort_all(t_stack **stack_a, t_stack **stack_b)
{
	int stack_len;

	stack_len = list_len(stack_a);
	if (stack_len == 1)
		return;
	if (stack_len == 2)
		sort_two_nbrs(stack_a);
	if (stack_len == 3)
		sort_three_nbrs(stack_a);
	if (stack_len == 4)
		sort_four_nbrs(stack_a, stack_b);
	if (stack_len == 5)
		sort_five_nbrs(stack_a, stack_b);
	if (stack_len > 5)
		sort_stack(stack_a, stack_b);
}
