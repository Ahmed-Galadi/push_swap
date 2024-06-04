/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:14:08 by agaladi           #+#    #+#             */
/*   Updated: 2024/03/31 05:46:54 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	error_accured(void)
{
	ft_putstr(ERROR_MSG);	
	exit(EXIT_FAILURE);
}

void	input_checker(int argc, char *argv[])
{
	// if (argc < 2)
		// error_accured();
	if (argc == 2)
		if (!check_input(argv[1]))
			error_accured();
	if (argc > 2)
		if (!is_valid_args(argv + 1, argc - 1))
			error_accured();
}
