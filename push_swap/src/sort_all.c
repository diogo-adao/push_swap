/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:01:08 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/02 18:23:06 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	final_sort(t_stacks *stacks)
{
	int		cheap;
	t_cost	cost_a;
	t_cost	cost_b;

	while (*(stacks->size_a) > 3)
	{
		cheap = find_cheapest(
				stacks->stacka, stacks->size_a, stacks->stackb, stacks->size_b);
		cost_a = calculate_cost_for_stack_a(cheap, stacks->size_a);
		cost_b = calculate_cost_for_stack_b(
				stacks->stacka[cheap], stacks->stackb, stacks->size_b);
		handle_both(&cost_a, &cost_b, stacks);
		handle_stack_a(&cost_a, stacks->stacka, stacks->size_a);
		handle_stack_b(&cost_b, stacks->stackb, stacks->size_b);
		ft_push(stacks->stacka, stacks->size_a, stacks->stackb, stacks->size_b);
		write(1, "pb\n", 3);
	}
}

void	sort_all(int *stacka, int *size_a, int *stackb, int *size_b)
{
	t_stacks	stacks;

	stacks.stacka = stacka;
	stacks.stackb = stackb;
	stacks.size_a = size_a;
	stacks.size_b = size_b;
	if (*size_a == 4)
	{
		ft_push(stacka, size_a, stackb, size_b);
		ft_printf("pb\n");
	}
	else
	{
		ft_push(stacka, size_a, stackb, size_b);
		ft_push(stacka, size_a, stackb, size_b);
		ft_printf("pb\n");
		ft_printf("pb\n");
	}
	final_sort(&stacks);
	sort_3(stacka, size_a);
	push_to_stack_a(stacka, size_a, stackb, size_b);
	minimum_to_top(stacka, size_a);
}
