/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 03:55:11 by agaladi           #+#    #+#             */
/*   Updated: 2024/03/08 18:19:04 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*str_to_int_tab(char *nbrs, int *a_len)
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
		nbrs_arr_output[i] = ft_atoi(splited_nbrs[i]);
		i++;
	}
	*a_len = count_words(nbrs, ' ');
	return (free(splited_nbrs),nbrs_arr_output);
}

int		*args_to_int_tab(char *args[], int arr_size)
{
	int		*output_tab;
	int		i;

	output_tab = (int *)malloc(arr_size * sizeof(int));
	if (!output_tab)
		return (NULL);
	i = 0;
	while(arr_size--)
	{
		output_tab[i] = ft_atoi(args[i]);
		i++;	
	}
	return (output_tab);
}

int	*input_formater(int argc, char *argv[], int *a_len)
{
	int		*output;

	input_checker(argc, argv);
	if (argc == 2)
		output = str_to_int_tab(argv[1], a_len);
	if (argc > 2)
	{
		output = args_to_int_tab(argv + 1, argc - 1);
		*a_len = argc - 1;	
	}
	if (!output)
		error_accured();
	if (!is_norep(output))
		error_accured();
	return (output);
}
