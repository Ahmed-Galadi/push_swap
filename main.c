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



void	print_list(t_stack *stack, char *name)
{
	t_stack	*current;

	current = stack;
	if (!stack)
		return ;
	printf("\nstack_%s\n", name);
    while (current != NULL) {
        printf("%d ", current->content);
        current = current->next;
    }
}

int	main(int argc, char *argv[])
{
	int		*input_int_arr;
	t_stack	*a;
	t_stack *b;
	int		a_len;

	input_int_arr = input_formater(argc, argv, &a_len);
	a = fill_a_stack(input_int_arr, a_len);
	b = NULL;

	push_b(&a, &b);
	push_b(&a, &b);
	push_b(&a, &b);
	push_a(&a, &b);
	// if (a_len == 1)
	// 	print_list(a, "a");
	// sort_all(&a, &b);
	print_list(a, "a");
	print_list(b, "b");




	while (a) 
	{
        t_stack *temp = a;
        a = a->next;
        free(temp);
    }
	free(input_int_arr);
	return (0);
}
