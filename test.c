#include <stdio.h>

size_t	arr_size(char **args)
{
	size_t	count;
	
	count = 0;
	while(args[count])
		count++;
	return (count);
}

int main()
{
	char *arr[] = {"1", "2", "3", "1", "2", "3", "1"};
	printf("%zu", sizeof(arr) /sizeof(char *));
	return (0);
}