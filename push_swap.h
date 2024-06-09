/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 03:55:59 by agaladi           #+#    #+#             */
/*   Updated: 2024/06/09 00:50:22 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

# define ERROR_MSG "Error\n"

typedef struct s_stack
{
	int				content;
	int				sorted_index;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

int		ft_isdigit(char character);
char	**ft_split(char const *s, char c);
int		is_norep(int *nbrs);
int		is_sorted(int *int_arr, int arr_len);
int		check_input(char *input);
int		is_valid_args(char **args, int size);
int		count_words(const char *str, char d);
int		*str_to_int_tab(char *nbrs, int *a_len);
int		*args_to_int_tab(char *args[], int arr_size);
int		ft_atoi(const char *str);
void	ft_putstr(char *str);
void	error_accured(void);
void	input_checker(int argc, char *argv[]);
int		*input_formater(int argc, char *argv[], int *a_len);
int		list_len(t_stack **stack);
t_stack	*create_stack(int content, t_stack *prev);
t_stack	*fill_a_stack(int *int_arr, int arr_len);
t_stack	*lst_last(t_stack **lst);
int		lowest_content(t_stack **stack);
void	swap(t_stack *stack, char name);
void	push(t_stack **from, t_stack **to, char name);
void	reverse_rotate(t_stack **stack, char name);
void	rotate(t_stack **stack, char name);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		find_position(t_stack **stack, int content);
void	bring_to_top(t_stack **stack, int content);
void	sort_two_nbrs(t_stack **stack_a);
void	sort_three_nbrs(t_stack **stack_a, t_stack **stack_b);
void	sort_four_nbrs(t_stack **stack_a, t_stack **stack_b);
void	sort_five_nbrs(t_stack **stack_a, t_stack **stack_b);
void	sort_all(t_stack **stack_a, t_stack **stack_b);
void	sort_int_tab(int *nbrs, int length);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	set_sorted_index(t_stack **stack, int *int_arr, int length);

#endif
