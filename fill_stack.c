/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:33:49 by agaladi           #+#    #+#             */
/*   Updated: 2024/03/27 02:52:52 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *create_stack(int content, t_stack *prev)
{
	t_stack *output_stack;

	output_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!output_stack)
		exit(EXIT_FAILURE);
	output_stack->prev = prev;
	output_stack->content = content;
	output_stack->next = NULL;
	return (output_stack);
}

t_stack *fill_a_stack(int *int_arr, int arr_len)
{
    t_stack	*output_stack;
	t_stack	*current;
	int		i;

	output_stack = create_stack(int_arr[0], NULL);
    if (!output_stack)
        exit(EXIT_FAILURE);
    current = output_stack;
	i = 1;
    while (i < arr_len) 
	{
        current->next = create_stack(int_arr[i], current);
        current = current->next;
		i++;
    }
    return (output_stack);
}
