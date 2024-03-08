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



int	main(int argc, char *argv[])
{
	int		*input_int_arr;
	t_stack	*a;
	//t_stack *b;
	int		a_len;

	input_int_arr = input_formater(argc, argv, &a_len);
	a = fill_a_stack(input_int_arr, a_len);
	
	t_stack *current = a;
	int i = 0;
	while (i < a_len)
	{
		printf("%d ", current->content);
		current = current->next;
		i++;
	}
	return (0);
}
