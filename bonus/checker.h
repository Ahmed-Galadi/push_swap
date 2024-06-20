/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaladi <agaladi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 03:16:22 by agaladi           #+#    #+#             */
/*   Updated: 2024/06/20 05:06:04 by agaladi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	int				sorted_index;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

void	checker_swap(t_stack *stack);
void	checker_push(t_stack **from, t_stack **to);
void	checker_rotate(t_stack **stack);
void	checker_reverse_rotate(t_stack **stack);

#endif