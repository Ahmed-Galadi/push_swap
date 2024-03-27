/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:06:29 by agaladi           #+#    #+#             */
/*   Updated: 2024/03/27 21:17:08 by agaladi          ###   ########.fr       */
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

t_stack *lst_last(t_stack *lst)
{
	t_stack	*current;
	int		lst_len;

	current = lst;
	lst_len = list_len(current);
	while (--lst_len)
		current = current->next;
	return (current);
}