/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:47:15 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/01 19:52:16 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_cost	calculate_cost_for_stack_a(int index_a, int *size_a)
{
	t_cost	info;

	if (index_a <= *size_a / 2)
	{
		info.cost = index_a;
		info.operation = 'u';
	}
	else
	{
		info.cost = *size_a - index_a;
		info.operation = 'd';
	}
	return (info);
}

t_cost	calculate_cost_for_stack_b(int value_a, int *stackb, int *size_b)
{
	t_cost	info;
	int		index_b;
	int		tmp;
	int		closest_index;

	index_b = 0;
	tmp = INT_MAX;
	closest_index = -1;
	if ((value_a > stackb[find_biggest(stackb, size_b)])
		|| (value_a < stackb[find_smallest(stackb, size_b)]))
		info = cost_for_biggest(find_biggest(stackb, size_b), size_b);
	else
	{
		while (index_b < *size_b)
		{
			if (value_a - stackb[index_b] > 0)
				closest_index
					= find_closer_index(
						value_a, stackb[index_b], index_b, &tmp);
			index_b++;
		}
		info = cost_for_closest(closest_index, size_b);
	}
	return (info);
}

int	calculate_total_cost(int index_a, t_stacks *stacks)
{
	t_cost	cost_a;
	t_cost	cost_b;

	cost_a = calculate_cost_for_stack_a(index_a, stacks->size_a);
	cost_b = calculate_cost_for_stack_b(
			stacks->stacka[index_a], stacks->stackb, stacks->size_b);
	if (cost_a.operation == cost_b.operation)
	{
		if (cost_a.cost > cost_b.cost)
			return (cost_a.cost + 1);
		else
			return (cost_b.cost + 1);
	}
	else
		return (cost_a.cost + cost_b.cost + 1);
}

int	find_cheapest(int *stacka, int *size_a, int *stackb, int *size_b)
{
	int			index_a;
	int			cost;
	int			final_cost;
	int			cheapest;
	t_stacks	stacks;

	index_a = 0;
	cost = INT_MAX;
	cheapest = 0;
	stacks.stacka = stacka;
	stacks.stackb = stackb;
	stacks.size_a = size_a;
	stacks.size_b = size_b;
	while (index_a < *size_a)
	{
		final_cost = calculate_total_cost(index_a, &stacks);
		cheapest = cheapest_one(index_a, final_cost, &cost, cheapest);
		index_a++;
	}
	return (cheapest);
}
