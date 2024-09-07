/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:37:00 by diolivei          #+#    #+#             */
/*   Updated: 2024/09/04 15:41:59 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_3_biggest(int *stack, int *size)
{
	int	i;
	int	n;

	i = 0;
	if (stack[i] > stack[i + 1])
	{
		if (stack[i] > stack[i + 2])
			n = stack[i];
		else
			n = stack[i + 2];
	}
	else
	{
		if (stack[i + 1] > stack[i + 2])
			n = stack[i + 1];
		else
			n = stack[i + 2];
	}
	return (n);
}

int	sort_3_cases(int *stack, int *size)
{
	int	cases;
	int	n;

	n = sort_3_biggest(stack, size);
	cases = 0;
	if (stack[0] == n)
	{
		if (stack[1] > stack[2])
			cases = 1;
		else
			cases = 2;
	}
	else if (stack[1] == n)
	{
		if (stack[0] < stack[2])
			cases = 3;
		else
			cases = 4;
	}
	else if (stack[2] == n)
	{
		if (stack[0] > stack[1])
			cases = 5;
	}
	return (cases);
}

int	print_sort_3(int *stack, int *size)
{
	int	cases;

	cases = sort_3_cases(stack, size);
	if (cases == 1)
	{
		ft_printf("sa\n");
		ft_printf("rra\n");
	}
	else if (cases == 2)
		ft_printf("ra\n");
	else if (cases == 3)
	{
		ft_printf("sa\n");
		ft_printf("ra\n");
	}
	else if (cases == 4)
		ft_printf("rra\n");
	else if (cases == 5)
		ft_printf("sa\n");
	return (cases);
}

void	sort_3(int *stack, int *size)
{
	int	cases;

	cases = print_sort_3(stack, size);
	if (cases == 1)
	{
		ft_swap(&stack[0], &stack[1], size);
		ft_reverse(stack, size);
	}
	else if (cases == 2)
		ft_rotate(stack, size);
	else if (cases == 3)
	{
		ft_swap(&stack[0], &stack[1], size);
		ft_rotate(stack, size);
	}
	else if (cases == 4)
		ft_reverse(stack, size);
	else if (cases == 5)
		ft_swap(&stack[0], &stack[1], size);
}
