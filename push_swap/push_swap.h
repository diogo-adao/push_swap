/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:01:01 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/01 19:46:37 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// Parameters
typedef struct s_stacks
{
	int	*stacka;
	int	*stackb;
	int	*size_a;
	int	*size_b;
}	t_stacks;

// Operations
void	ft_rotate(int *stack, int *size);
void	ft_reverse(int *stack, int *size);
void	ft_swap(int *n1, int *n2, int *size);
void	ft_push(int *stack1, int *size_1, int *stack2, int *size_2);

// Handlers
int		is_sorted(int *stack, int *size);
int		is_error(char *arg, int *stacka, int size);

// Algorithms
void	sort_2(int *stack, int *size);
void	sort_3(int *stack, int *size);
void	sort_all(int *stacka, int *size_a, int *stackb, int *size_b);

// Utils
int		find_biggest(int *stack, int *size);
int		find_smallest(int *stack, int *size);
void	minimum_to_top(int *stacka, int *size_a);
void	rotate_stack_a(int *stacka, int *size_a, int position);
int		find_correct_position(int *stacka, int *size_a, int value);
int		find_cheapest(int *stacka, int *size_a, int *stackb, int *size_b);
int		cheapest_one(int index_a, int total_cost, int *cost, int cheapest);
void	push_to_stack_a(int *stacka, int *size_a, int *stackb, int *size_b);
int		find_closer_index(int current_a, int current_b, int index_b, int *tmp);

// Struct
typedef struct s_cost
{
	int		cost;
	char	operation;
}	t_cost;

void	handle_stack_a(t_cost *cost_a, int *stacka, int *size_a);
void	handle_stack_b(t_cost *cost_b, int *stackb, int *size_b);
void	handle_both(t_cost *cost_a, t_cost *cost_b, t_stacks *stacks);
t_cost	cost_for_biggest(int biggest, int *size_b);
t_cost	cost_for_closest(int closer_index, int *size_b);
t_cost	calculate_cost_for_stack_a(int index_a, int *size_a);
t_cost	calculate_cost_for_stack_b(int value_a, int *stackb, int *size_b);

#endif
