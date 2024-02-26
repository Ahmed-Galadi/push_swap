/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 03:51:08 by agaladi           #+#    #+#             */
/*   Updated: 2024/02/26 04:44:43 by agaladi          ###   ########.fr       */
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


int	main(int argc, char *argv[])
{
	if (argc < 2)
		error_accured();
	if (argc == 2)
	{
		if ()
	}
		
	ft_putstr(argv[1]);
	return (0);
}