/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 03:51:08 by agaladi           #+#    #+#             */
/*   Updated: 2024/02/24 20:37:29 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main()
{
	int nbrs[16] = {5,2,4,6,9,8,7 ,(int)NULL};

	printf("%d", is_norep(nbrs));
	return (0);
}