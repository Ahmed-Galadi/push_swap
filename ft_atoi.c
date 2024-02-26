/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 04:35:35 by agaladi           #+#    #+#             */
/*   Updated: 2024/02/26 04:36:22 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		||c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(const char *nptr)
{
	unsigned long output;
	int				sign;
	int				i;

	output = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		output = output * 10 + (nptr[i] - '0');
		if (output > 9223372036854775807UL && sign == 1)
			return (-1);
		if (output > 9223372036854775807UL && sign == -1)
			return (0);
		i++;
	}
	return (output * sign);
}