/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:36:40 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/01 19:57:49 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_biggest(int *stack, int *size)
{
	int	i;
	int	index;
	int	biggest_value;

	i = 0;
	biggest_value = INT_MIN;
	while (i < *size)
	{
		if (stack[i] > biggest_value)
		{
			biggest_value = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	find_smallest(int *stack, int *size)
{
	int	i;
	int	index;
	int	smallest_value;

	i = 0;
	smallest_value = INT_MAX;
	while (i < *size)
	{
		if (stack[i] < smallest_value)
		{
			smallest_value = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	find_closer_index(int current_a, int current_b, int index_b, int *tmp)
{
	int			diff;
	static int	closer_index;

	diff = current_a - current_b;
	if (*tmp > diff)
	{
		*tmp = diff;
		closer_index = index_b;
	}
	return (closer_index);
}

int	find_correct_position(int *stacka, int *size_a, int value)
{
	int	i;
	int	closest_index;
	int	tmp;

	i = 0;
	closest_index = -1;
	tmp = INT_MAX;
	if ((value > stacka[find_biggest(stacka, size_a)])
		|| (value < stacka[find_smallest(stacka, size_a)]))
		closest_index = find_smallest(stacka, size_a);
	else
	{
		while (i < *size_a)
		{
			if (value - stacka[i] < 0)
				closest_index = find_closer_index(stacka[i], value, i, &tmp);
			i++;
		}
	}
	return (closest_index);
}
