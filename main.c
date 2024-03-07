/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 03:51:08 by agaladi           #+#    #+#             */
/*   Updated: 2024/02/26 08:19:08 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *create_stack(int content, t_stack *prev)
{
	t_stack *output_stack;

	output_stack = (t_stack *)malloc(sizeof(t_stack *));
	if (!output_stack)
		return (NULL);
	output_stack->prev = prev;
	output_stack->content = content;
	output_stack->next = NULL;
	return (output_stack);
}

// t_stack *fill_a_stack(int *int_arr, int arr_len)
// {
// 	t_stack	*output_stack;
// 	int		i;
	

// 	i = 0;
// 	while (arr_len--)
// 	{
		
// 	}
// }

int	main(int argc, char *argv[])
{
	int		*input_int_arr;
	t_stack	*a;
	t_stack *b;

	input_int_arr = input_formater(argc, argv);
	

	return (0);
}
