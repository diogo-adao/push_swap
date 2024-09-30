/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:36:40 by diolivei          #+#    #+#             */
/*   Updated: 2024/09/30 14:43:43 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_biggest(int *stack, int *size)
{
    int i;
    int biggest_value;
    int index;

	i = 0;
	biggest_value = INT_MIN;
	while(i < *size)
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

int find_smallest(int *stack, int *size)
{
    int i;
    int smallest_value;
    int index;

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

int find_closer_index(int current_a, int current_b, int index_b, int *tmp, int closer_index)
{
    int diff;

    diff = current_a - current_b;
    if (*tmp > diff)
    {
        *tmp = diff;
        closer_index = index_b;
    }
    return (closer_index);
}
