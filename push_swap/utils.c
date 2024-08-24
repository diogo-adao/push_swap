#include "libft/libft.h"

int is_duplicate(int *arr, int size, int n)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == n)
			return (1);
		i++;
	}
	return (0);
}