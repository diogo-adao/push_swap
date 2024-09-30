/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:01:01 by diolivei          #+#    #+#             */
/*   Updated: 2024/09/30 14:43:02 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct {
    int cost;
    char operation;
} t_cost;

// Operations
void	ft_swap(int *n1, int *n2, int *size);
void	ft_push(int *stack1, int *size_1, int *stack2, int *size_2);
void	ft_rotate(int *stack, int *size);
void	ft_reverse(int *stack, int *size);

// Handlers
int		is_error(char *arg, int *stacka, int size);
int		is_sorted(int *stack, int *size);

// Algorithms
void	sort_2(int *stack, int *size);
void	sort_3(int *stack, int *size);
void	sort_all(int *stacka, int *size_a, int *stackb, int *size_b);

// Utils
int find_biggest(int *stack, int *size);
int find_smallest(int *stack, int *size);
t_cost cost_for_biggest(int biggest, int *size_b);
int find_closer_index(int current_a, int current_b, int index_b, int *tmp, int closer_index);
t_cost cost_for_closest(int closer_index, int *size_b);
int cheapest_one(int index_a, int total_cost, int *cost, int cheapest);

#endif
