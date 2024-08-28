/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:36:40 by diolivei          #+#    #+#             */
/*   Updated: 2024/08/28 15:17:15 by diolivei         ###   ########.fr       */
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

int sort_3_biggest(int *stack, int *size)
{
	int i;
	int n;

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
