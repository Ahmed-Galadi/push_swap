/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 06:44:42 by agaladi           #+#    #+#             */
/*   Updated: 2024/02/26 04:43:45 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isdigit(char character)
{
	return (character >= '0' && character <= '9');
}

static int		is_norep(int *nbrs)
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

static int 	check_input(char *input)
{
	int		i;

	i = 0;
	while (input[i])
	{
		if (!ft_isdigit(input[i]) && input[i] != ' ')
			return (0);
		i++;
	}
	return (0);
}
int 	is_valid_arr(char **args)
{
	
}

int		is_valid_str(char *input)
{
}


