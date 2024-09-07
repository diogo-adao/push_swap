#include "push_swap.h"

int	is_duplicate(int *arr, int size, int n)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == n)
			return (1);
		i++;
	}
	return (0);
}

int	is_error(char *arg, int *stacka, int size)
{
	int	i;
	int	overflow;
	int	n;

	i = 0;
	overflow = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!arg[i])
		return (1);
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	n = ft_atoi(arg, &overflow);
	if (overflow)
		return (1);
	if (is_duplicate(stacka, size, n))
		return (1);
	return (0);
}