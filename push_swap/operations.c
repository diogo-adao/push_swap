/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:43:43 by diolivei          #+#    #+#             */
/*   Updated: 2024/08/27 14:44:32 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *n1, int *n2, int *size)
{
	int	tmp;

	if (*size > 1)
	{
		tmp = *n1;
		*n1 = *n2;
		*n2 = tmp;
	}
}

void	ft_push(int *stack1, int *size_1, int *stack2, int *size_2)
{
	int	i;

	i = *size_2;
	if (*size_1 > 0)
	{
		while (i > 0)
		{
			stack2[i] = stack2[i - 1];
			i--;
		}
		stack2[0] = stack1[0];
		(*size_2)++;
		i = 0;
		while (i < *size_1 - 1)
		{
			stack1[i] = stack1[i + 1];
			i++;
		}
		(*size_1)--;
	}
}

void	ft_rotate(int *stack, int *size)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack[i];
	if (*size > 1)
	{
		while (i < *size - 1)
		{
			stack[i] = stack[i + 1];
			i++;
		}
		stack[i] = tmp;
	}
}

void	ft_reverse(int *stack, int *size)
{
	int	i;
	int	tmp;

	i = *size;
	tmp = stack[i - 1];
	if (*size > 1)
	{
		while (i > 0)
		{
			stack[i] = stack[i - 1];
			i--;
		}
		stack[i] = tmp;
	}
}
