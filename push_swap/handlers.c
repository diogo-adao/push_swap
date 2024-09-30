/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:01:17 by diolivei          #+#    #+#             */
/*   Updated: 2024/09/17 14:01:18 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(int *stack, int *size)
{
	if (stack[0] > stack[1])
	{
		ft_printf("sa\n");
		ft_swap(&stack[0], &stack[1], size);
	}
}

int	is_sorted(int *stack, int *size)
{
	int	i;

	i = 0;
	while (i < *size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

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
