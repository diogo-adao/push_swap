/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:58:13 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/01 20:00:37 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_cost	cost_for_biggest(int biggest, int *size_b)
{
	t_cost	info;

	if (biggest <= *size_b / 2)
	{
		info.cost = biggest;
		info.operation = 'u';
	}
	else
	{
		info.cost = *size_b - biggest;
		info.operation = 'd';
	}
	return (info);
}

t_cost	cost_for_closest(int closer_index, int *size_b)
{
	t_cost	info;

	if (closer_index <= *size_b / 2)
	{
		info.cost = closer_index;
		info.operation = 'u';
	}
	else
	{
		info.cost = *size_b - closer_index;
		info.operation = 'd';
	}
	return (info);
}

int	cheapest_one(int index_a, int total_cost, int *cost, int cheapest)
{
	if (*cost > total_cost)
	{
		*cost = total_cost;
		cheapest = index_a;
	}
	return (cheapest);
}

void	rotate_stack_a(int *stacka, int *size_a, int position)
{
	if (position <= *size_a / 2)
	{
		while (position > 0)
		{
			ft_rotate(stacka, size_a);
			position--;
			ft_printf("ra\n");
		}
	}
	else
	{
		position = *size_a - position;
		while (position > 0)
		{
			ft_reverse(stacka, size_a);
			position--;
			ft_printf("rra\n");
		}
	}
}

void	minimum_to_top(int *stacka, int *size_a)
{
	int	i;
	int	min;

	i = 0;
	min = find_smallest(stacka, size_a);
	if (min <= *size_a / 2)
	{
		while (min > 0)
		{
			ft_rotate(stacka, size_a);
			min--;
			ft_printf("ra\n");
		}
	}
	else
	{
		min = *size_a - min;
		while (min > 0)
		{
			ft_reverse(stacka, size_a);
			min--;
			ft_printf("rra\n");
		}
	}
}
