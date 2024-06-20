/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 05:33:12 by agaladi           #+#    #+#             */
/*   Updated: 2024/06/20 05:53:28 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_strcmp(char *str1, char *str2)
{
	while (*str1)
		if (*(str1++) != *(str2++))
			return (0);
	return (1);
}



void	execute_actions(stack_t **stack_a, stack_t **stack_b, char *action)
{
	if (ft_strcmp(action, "sa\n"))
		checker_swap(*stack_a);
	else if (ft_strcmp(action, "sb\n"))
		checker_swap(*stack_a);
	else if (ft_strcmp(action, "ss\n"))
}