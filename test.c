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

void	lst_add_first(t_stack **lst, int new_lst_content)
{
	t_stack	*new_lst;

	new_lst = create_stack(new_lst_content, NULL);
	new_lst->next = *lst;
	*lst = new_lst;
}

void lst_add_last(t_stack **lst, int content) {
    t_stack *to_add_lst = create_stack(content, NULL);
    if (*lst == NULL) {
        *lst = to_add_lst;
        return;
    }
    t_stack *current = *lst;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = to_add_lst;
    to_add_lst->prev = current;
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
}

int main() {
    int nbrs[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int nbrs1[] = {30,40,50,60,70,80,90};
    // t_stack *stack = fill_a_stack(nbrs, 20);
	t_stack *stack = NULL;
	t_stack *stack1 = fill_a_stack(nbrs1, 7);
	// t_stack *stack1 = NULL;

	swap_a(stack);

    // printf("\nstack length = %d | stack1 length = %d", list_len(&stack), list_len(&stack1));
    // printf("\nstackfirst content : %d | stack1 first content : %d", stack->content, stack1->content);
    // printf("\nstack last content = %d | stack1 last content = %d", lst_last(&stack)->content, lst_last(&stack1)->content);

    return 0;
}
