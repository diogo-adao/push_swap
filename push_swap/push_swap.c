/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:37:07 by diolivei          #+#    #+#             */
/*   Updated: 2024/08/08 19:31:36 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void push_swap(int *stacka, int *size_a, int *stackb, int *size_b)
{
	//ft_swap(&stacka[0], &stacka[1], size_a);
	//ft_push(stacka, size_a, stackb, size_b);
	//ft_rotate(stacka, size_a);
	//ft_reverse(stacka, size_a);
}

int is_error(char *arg)
{
	int i = 0;
	int overflow = 0;
    int n;

	// Check for spaces and signs
    while (arg[i] == ' ' || arg[i] == '\t' || arg[i] == '\r'
        || arg[i] == '\f' || arg[i] == '\v' || arg[i] == '\n')
        i++;

    if (arg[i] == '-' || arg[i] == '+')
        i++;

    // If the string ends after the sign, return error
    if (!arg[i])
        return 1;
        
	// Return error if non-digit found
    while (arg[i])
    {
        if (arg[i] < '0' || arg[i] > '9')
            return 1;
        i++;
    }

    // Check if the number is within the valid range
    n = ft_atoi(arg, &overflow);
	if (overflow)
		return (1);

    return 0;
}

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		int size = argc - 1;
		int stacka[size];
		int stackb[size];
		int size_a = size;
		int size_b = 0;

		int i = 0;
		while (i < size)
		{
			if (is_error(argv[i + 1]))
				return (write(2, "Error\n", 6));
			stacka[i] = ft_atoi(argv[i + 1], NULL);
			i++;
		}
		push_swap(stacka, &size_a, stackb, &size_b);
		i = 0;
		ft_printf("stack A:\n");
		while (i < size_a)
		{
			ft_printf("%d\n", stacka[i]);
			i++;
		}
		i = 0;
		ft_printf("stack B:\n");
		while (i < size_b)
		{
			ft_printf("%d\n", stackb[i]);
			i++;
		}
	}
	return (0);
}
