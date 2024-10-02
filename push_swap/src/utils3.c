/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:00:50 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/02 17:04:54 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	handle_both(t_cost *cost_a, t_cost *cost_b, t_stacks *stacks)
{
	while (cost_a->cost > 0 && cost_b->cost > 0)
	{
		if (cost_a->operation == 'u' && cost_b->operation == 'u')
		{
			ft_rotate(stacks->stacka, stacks->size_a);
			ft_rotate(stacks->stackb, stacks->size_b);
			ft_printf("rr\n");
			cost_a->cost--;
			cost_b->cost--;
		}
		else if (cost_a->operation == 'd' && cost_b->operation == 'd')
		{
			ft_reverse(stacks->stacka, stacks->size_a);
			ft_reverse(stacks->stackb, stacks->size_b);
			ft_printf("rrr\n");
			cost_a->cost--;
			cost_b->cost--;
		}
		else
			break ;
	}
}

void	handle_stack_a(t_cost *cost_a, int *stacka, int *size_a)
{
	int	i;

	i = 0;
	while (i < cost_a->cost)
	{
		if (cost_a->operation == 'u')
		{
			ft_rotate(stacka, size_a);
			ft_printf("ra\n");
		}
		else if (cost_a->operation == 'd')
		{
			ft_reverse(stacka, size_a);
			ft_printf("rra\n");
		}
		i++;
	}
}

void	handle_stack_b(t_cost *cost_b, int *stackb, int *size_b)
{
	int	i;

	i = 0;
	while (i < cost_b->cost)
	{
		if (cost_b->operation == 'u')
		{
			ft_rotate(stackb, size_b);
			ft_printf("rb\n");
		}
		else if (cost_b->operation == 'd')
		{
			ft_reverse(stackb, size_b);
			ft_printf("rrb\n");
		}
		i++;
	}
}

void	push_to_stack_a(int *stacka, int *size_a, int *stackb, int *size_b)
{
	int	value_to_push;
	int	position;

	while (*size_b > 0)
	{
		value_to_push = stackb[0];
		position = find_correct_position(stacka, size_a, value_to_push);
		rotate_stack_a(stacka, size_a, position);
		ft_push(stackb, size_b, stacka, size_a);
		ft_printf("pa\n");
	}
}
