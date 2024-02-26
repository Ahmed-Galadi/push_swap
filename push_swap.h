/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 03:55:59 by agaladi           #+#    #+#             */
/*   Updated: 2024/02/26 05:08:10 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

# define ERROR_MSG "Please Enter:\t./push_swap \"<enter your numbers as a string separated with a space>\"\n\
\t  or:\t./push_swap <enter your numbers directly as args>"

int		ft_isdigit(char character);
char	**ft_split(char const *s, char c);
int		is_norep(int *nbrs);
int		check_input(char *input);
int 	is_valid_args(char **args, int size);
int		count_words(const char *str, char d);
int		*str_to_int_tab(char *nbrs);
int		*args_to_int_tab(char *args[], int arr_size);
int		ft_atoi(const char *nptr);

#endif