/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 03:55:55 by agaladi           #+#    #+#             */
/*   Updated: 2024/06/16 04:38:08 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack **stack, int **input_arr)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	free(*input_arr);
}

int	main(int argc, char *argv[])
{
	int		*input_int_arr;
	t_stack	*a;
	t_stack	*b;
	int		a_len;

	input_int_arr = input_formater(argc, argv, &a_len);
	a = fill_a_stack(input_int_arr, a_len);
	b = NULL;
	sort_all(&a, &b);
	free_all(&a, &input_int_arr);
	return (0);
}
