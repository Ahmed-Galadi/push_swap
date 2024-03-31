#include <libc.h>


void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		ft_isdigit(char character)
{
	return (character >= '0' && character <= '9');
}

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

int 	check_input(char *input)
{
	int		i;

	i = 0;
	while (input[i])
	{
		if (!ft_isdigit(input[i]) && input[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
int 	is_valid_args(char **args, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}


typedef struct		s_stack
{
	int				content;
	struct	s_stack	*prev;
	struct	s_stack	*next;
	
}					t_stack;

t_stack *create_stack(int content, t_stack *prev)
{
	t_stack *output_stack;

	output_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!output_stack)
		exit(EXIT_FAILURE);
	output_stack->prev = prev;
	output_stack->content = content;
	output_stack->next = NULL;
	return (output_stack);
}

t_stack *fill_a_stack(int *int_arr, int arr_len)
{
    t_stack	*output_stack;
	t_stack	*current;
	int		i;

	output_stack = create_stack(int_arr[0], NULL);
    if (!output_stack)
        exit(EXIT_FAILURE);
    current = output_stack;
	i = 1;
    while (i < arr_len) 
	{
        current->next = create_stack(int_arr[i], current);
        current = current->next;
		i++;
    }
    return (output_stack);
}

int list_len(t_stack **stack) {
    t_stack *current = *stack;
    int len = 1;
    while (current->next) {
        current = current->next;
        len++;
    }
    return len;
}


t_stack *lst_last(t_stack **lst)
{
	t_stack	*current;
	
	if (!*lst)
		return (NULL);
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	return (current);
}



void	print_list(t_stack *stack, char *name)
{
	t_stack	*current;

	current = stack;
	printf("\nstack_%s\n", name);
    while (current != NULL) {
        printf("%d ", current->content);
        current = current->next;
    }
}


// *-----------------------------------------------------*

void	swap_a(t_stack *stack_a)
{
	t_stack	*current;
	int		temp;

	if (!stack_a)
		return ;
	current = stack_a;
	temp = current->content;
	current->content = current->next->content;
	current->next->content = temp;
	ft_putstr("\nsa");
}

void	swap_b(t_stack *stack_b)
{
	t_stack	*current;
	int		temp;

	if (!stack_b)
		return ;
	current = stack_b;
	temp = current->content;
	current->content = current->next->content;
	current->next->content = temp;
	ft_putstr("\nsb");
}

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_putstr("\nss");
}

void rotate_a(t_stack **stack_a)
{
	t_stack *last_node;
	t_stack *current;

	if (!*stack_a)
		return;
	last_node = lst_last(stack_a);
	current = *stack_a;
	*stack_a = current->next;
	current->next->prev = NULL;
	current->prev = last_node;
	current->next = NULL;
	last_node->next = current;
	ft_putstr("\nra");
}

void rotate_b(t_stack **stack_b)
{
	t_stack *last_node;
	t_stack *current;

	if (!*stack_b)
		return;
	last_node = lst_last(stack_b);
	current = *stack_b;
	*stack_b = current->next;
	current->next->prev = NULL;
	current->prev = last_node;
	current->next = NULL;
	last_node->next = current;
	ft_putstr("\nrb");
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_putstr("\nrr");
}

void reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*last_node;
	t_stack	*current;

	if (!*stack_a)
		return;
	last_node = lst_last(stack_a);
	current = *stack_a;
	current->prev = last_node;
	last_node->next = current;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	current = current->prev;
	*stack_a = current;
	ft_putstr("\nrra");
}

void reverse_rotate_b(t_stack **stack_b)
{
	t_stack	*last_node;
	t_stack	*current;

	if (!*stack_b)
		return;
	last_node = lst_last(stack_b);
	current = *stack_b;
	current->prev = last_node;
	last_node->next = current;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	current = current->prev;
	*stack_b = current;
	ft_putstr("\nrrb");
}

void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	ft_putstr("\nrrr");
}

void push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *current_a;
	t_stack *current_b;

	current_a = *stack_a;
	current_b = *stack_b;
	if (!*stack_b)
		exit(EXIT_FAILURE);
	else if (!*stack_a)
	{
		current_a = current_b;
		current_b = current_b->next;
		current_b->prev = NULL;
		current_a->next = NULL;
		*stack_a = current_a;
		*stack_b = current_b;
	}
	else
	{
		*stack_b = current_b->next;
		current_b->next = *stack_a;
		current_a->prev = current_b;
		*stack_a = current_a->prev;
	}
	ft_putstr("\npa");
}

void push_b(t_stack **stack_b, t_stack **stack_a)
{
	t_stack *current_a;
	t_stack *current_b;

	current_a = *stack_a;
	current_b = *stack_b;
	if (!*stack_b)
		exit(EXIT_FAILURE);
	else if (!*stack_a)
	{
		current_a = current_b;
		current_b = current_b->next;
		current_b->prev = NULL;
		current_a->next = NULL;
		*stack_a = current_a;
		*stack_b = current_b;
	}
	else
	{
		*stack_b = current_b->next;
		current_b->next = *stack_a;
		current_a->prev = current_b;
		*stack_a = current_a->prev;
	}
	ft_putstr("\npb");
}
// *-----------------------------------------------------*
//					2			1		   3
// case_1 :		  midle      little       big

int	is_case_1(int first, int second, int third)
{
	if (first > second && first < third)
	{
		if (second < third)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

//				   3		  2		     1
// case_2 :		  big      middle      little
int is_case_2(int first, int second, int third)
{
	if (first > second && first > third)
	{
		if (second > third)
			return (1);
		else 
			return (0);
	}
	else 
		return (0);
}

//				   3		   1		     2
// case_3 :		  big        little        middle
int is_case_3(int first, int second, int third)
{
	if (first > second && first > third)
	{
		if (second < third)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

//                   1         3           2  
// case_4 :		  little      big       middle
int is_case_4(int first, int second, int third)
{
	if (first < second && first < third)
	{
		if (second > third)
			return (1);
		else
			return (0);
	}
	else 
		return (0);
}

void	sort_three_nbrs(t_stack **stack_a)
{
	t_stack	*stack;
	int		first;
	int		second;
	int		third;

	stack = *stack_a;
	first = stack->content;
	second = stack->next->content;
	third = stack->next->next->content;
	if (is_case_1(first, second, third))
		swap_a(*stack_a);
	else if (is_case_2(first, second, third))
	{
		swap_a(*stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (is_case_3(first, second, third))
		rotate_a(stack_a);
	else if (is_case_4(first, second, third))
	{
		swap_a(*stack_a);
		rotate_a(stack_a);
	}
	else
		reverse_rotate_a(stack_a);
}

int main()
{
	int nbrs_to_sort[] = {2255, 2296, 2254};

	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = fill_a_stack(nbrs_to_sort, 3);
	sort_three_nbrs(&stack_a);
	print_list(stack_a, "a");
    return 0;
}
