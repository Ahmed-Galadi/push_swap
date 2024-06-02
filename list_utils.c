/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:06:29 by agaladi           #+#    #+#             */
/*   Updated: 2024/06/02 19:10:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int list_len(t_stack **stack)
{
    t_stack *current;
	int		len;

	if (!*stack)
		return (0);
	current = *stack;
    len = 1;
    while (current->next)
	{
        current = current->next;
        len++;
    }
    return (len);
}

t_stack *lst_last(t_stack **lst)
{
	t_stack	*current;
	
	if (!*lst)
		return (NULL);
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

int	lowest_content(t_stack **stack)
{
	t_stack	*current;
	int		output;

	current = *stack;
	output = current->content;
	while (current)
	{
		if (current->content < output)
			output = current->content;
		current = current->next;
	}
	return (output);
}

int max_content(t_stack **stack)
{
	t_stack *current;
	int output;

	current = *stack;
	output = current->content;
	while (current)
	{
		if (current->content > output)
			output = current->content;
		current = current->next;
	}
	return (output);
}

int	find_position(t_stack **stack, int content)
{
	t_stack	*current;
	int		output;

	current = *stack;
	output = 1;
	while (current)
	{
		if (current->content == content)
			break ;
		current = current->next;
		output++;
	}
	return (output);
}