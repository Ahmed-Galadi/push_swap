#include <libc.h>


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
	t_stack *current;
	int		i;

	i = 1;
	output_stack = create_stack(int_arr[0], NULL);
	if (!output_stack)
		exit(EXIT_FAILURE);
	current = output_stack;
	while (arr_len--)
	{
		current->next = create_stack(int_arr[i], current);
		current = current->next;
		i++;
	}
	return (output_stack);
}

int		list_len(t_stack *stack)
{
	t_stack		*current;
	int			len;

	current = stack;
	len = 0;
	while (current->next)
	{
		current = current->next;
		len++;
	}
	return (len);
}

void	swap_a(t_stack *stack_a)
{
	t_stack	*current;
	int		temp;

	current = stack_a;
	temp = current->content;
	current->content = current->next->content;
	current->next->content = temp;
}

t_stack *lst_last(t_stack *lst)
{
	t_stack	*current;
	int		lst_len;

	current = lst;
	lst_len = list_len(current);
	while (--lst_len)
		current = current->next;
	return (current);
}

void	rotate_a(t_stack *stack_a)
{
	t_stack	*current;
	int		temp;

	current = stack_a;
	temp = current->content;
	current->content = lst_last(stack_a)->content;
	lst_last(stack_a)->content = temp;
}

int main()
{
	int nbrs[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	t_stack *stack = fill_a_stack(nbrs, 20);
	swap_a(stack);
	rotate_a(stack);
	t_stack *current = stack;
	int i = 0;
	while (i < 20)
	{
		printf("%d ", current->content);
		current = current->next;
		i++;
	}
	printf("\nlength = %d", list_len(stack));
	printf("\nlast content = %d", lst_last(stack)->content);
	return (0);
}
