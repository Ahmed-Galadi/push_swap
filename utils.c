/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 03:55:11 by agaladi           #+#    #+#             */
/*   Updated: 2024/02/25 06:17:17 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isdigit(char character)
{
	return (character >= '0' && character <= '9');
}

int		is_norep(int *nbrs)
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

int 	check_input(char *input)
{
	int		i;

	i = 0;
	while (input[i])
	{
		if (!ft_isdigit(input[i]) || input[i] != ' ')
			return (0);
		i++;
	}
	return (0);
}

int		*generate_int_tab(char *nbrs)
{
	char	**splited_nbrs;
	int		*nbrs_arr_output;
	int		i;

	splited_nbrs = ft_split(nbrs, ' ');
	if (!splited_nbrs)
		return (NULL);
	nbrs_arr_output = malloc(count_words(nbrs, ' ') * sizeof(int));
	if (!nbrs_arr_output)
		return (NULL);
	i = 0;
	while (splited_nbrs[i])
	{
		nbrs_arr_output[i] = splited_nbrs[i][0] - '0';
		i++;
	}
	return (free(splited_nbrs),nbrs_arr_output);
}
