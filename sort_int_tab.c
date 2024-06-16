/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 00:09:33 by agaladi           #+#    #+#             */
/*   Updated: 2024/06/16 04:34:50 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_int_position(int *nbrs, int length, int index)
{
	int		min;
	int		min_position;
	int		i;

	min = *nbrs;
	min_position = 0;
	i = 0;
	while (i < length)
	{
		if (nbrs[i] < min)
		{
			min = nbrs[i];
			min_position = i;
		}
		i++;
	}
	return (min_position + index);
}

void	sort_int_tab(int *nbrs, int length)
{
	int		min_position;
	int		tmp;
	int		i;

	i = 0;
	while ((length - 1))
	{
		min_position = min_int_position((nbrs + i), length--, i);
		tmp = nbrs[i];
		nbrs[i] = nbrs[min_position];
		nbrs[min_position] = tmp;
		i++;
	}
}
