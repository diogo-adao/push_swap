/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:36:40 by diolivei          #+#    #+#             */
/*   Updated: 2024/09/04 15:30:07 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

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
