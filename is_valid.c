/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 06:44:42 by agaladi           #+#    #+#             */
/*   Updated: 2024/06/27 17:21:54 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char character)
{
	return (character >= '0' && character <= '9');
}

int	is_norep(int *nbrs)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = 0;
	while (nbrs[i])
	{
		j = 0;
		while (nbrs[j])
		{
			if (nbrs[i] == nbrs[j])
				count++;
			j++;
		}
		if (2 <= count)
			return (0);
		count = 0;
		i++;
	}
	return (1);
}

int	has_nbrs(char *input)
{
	int		i;

	i = 0;
	while (input[i])
		if (ft_isdigit(input[i++]))
			return (1);
	return (0);
}

int	check_input(char *input)
{
	int		i;

	i = 0;
	if (!has_nbrs(input))
		error_accured();
	while (input[i])
	{
		if ((input[i] == '-' || input[i] == '+')
			&& (ft_isdigit(input[i - 1]) || !ft_isdigit(input[i + 1])))
			return (0);
		if (!ft_isdigit(input[i]) && input[i] != ' '
			&& input[i] != '+' && input[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_args(char **args, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (!check_input(args[i]))
			return (0);
		i++;
	}
	return (1);
}
