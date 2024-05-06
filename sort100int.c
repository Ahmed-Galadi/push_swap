/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort100int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:39:33 by agaladi           #+#    #+#             */
/*   Updated: 2024/05/06 21:04:14 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    set_n(int *n, int stack_size)
{
    if (stack_size <= 10)
        *n = 5;
    if (stack_size > 10 && stack_size <= 150)
        *n = 8;
    if (stack_size > 150)
        *n = 18;
}

void	sort100int(t_stack **stack_a, t_stack **stack_b)
{
    int     stack_size;
	int     n;
    int     middle;
    int     offset;
    int     start;
    int     end;

    stack_size = list_len(stack_a);
    set_n(&n, stack_size);
    offset = stack_size / n;
    middle = stack_size / 2;
    
}