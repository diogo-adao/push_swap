/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:01:08 by diolivei          #+#    #+#             */
/*   Updated: 2024/09/30 19:16:17 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cost calculate_cost_for_stack_a(int index_a, int *size_a)
{
    t_cost info;

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

t_cost calculate_cost_for_stack_b(int value_a, int *stackb, int *size_b)
{
    int index_b;
    int closest_index;
    t_cost info;
    int tmp;

    index_b = 0;
    tmp = INT_MAX;
	closest_index = -1;
    if ((value_a > stackb[find_biggest(stackb, size_b)]) || (value_a < stackb[find_smallest(stackb, size_b)]))
        info = cost_for_biggest(find_biggest(stackb, size_b), size_b);
    else
    {
        while (index_b < *size_b)
        {
            if (value_a - stackb[index_b] > 0)
                closest_index = find_closer_index(value_a, stackb[index_b], index_b, &tmp, closest_index);
            index_b++;
        }
        info = cost_for_closest(closest_index, size_b);
    }
    return (info);
}

int calculate_total_cost(t_cost cost_a, t_cost cost_b)
{
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

int get_final_cost(int index_a, int *stacka, int *stackb, int *size_a, int *size_b)
{
    t_cost total_cost_a;
    t_cost total_cost_b;

    total_cost_a = calculate_cost_for_stack_a(index_a, size_a);
    total_cost_b= calculate_cost_for_stack_b(stacka[index_a], stackb, size_b);
    return calculate_total_cost(total_cost_a, total_cost_b);
}

int find_cheapest(int *stacka, int *size_a, int *stackb, int *size_b)
{
    int index_a;
    int final_cost;
    int cheapest;
    int cost;

    index_a = 0;
    cost = INT_MAX;
    cheapest = 0;  // Initialize cheapest to a valid starting value (e.g., index 0)

    while (index_a < *size_a)
    {
        final_cost = get_final_cost(index_a, stacka, stackb, size_a, size_b);
        cheapest = cheapest_one(index_a, final_cost, &cost, cheapest);
        index_a++;
    }
    return (cheapest);
}

int find_correct_position(int *stacka, int *size_a, int value)
{
    int i = 0;
    int closest_index;
    int tmp = INT_MAX;

	closest_index = -1;
    while (i < *size_a)
    {
        if (value - stacka[i] < 0)
            closest_index = find_closer_index(stacka[i], value, i, &tmp, closest_index);
        i++;
    }
    return (closest_index);
}

void push_to_stack_a(int *stacka, int *size_a, int *stackb, int *size_b)
{
    while (*size_b > 0)
    {
        int value_to_push = stackb[0];
        int position = find_correct_position(stacka, size_a, value_to_push);

        if (position <= *size_a / 2)
        {
            while (position > 0)
            {
                ft_rotate(stacka, size_a);
                position--;
                ft_printf("ra ");
            }
        }
        else
        {
            position = *size_a - position;
            while (position > 0)
            {
                ft_reverse(stacka, size_a);
                position--;
                ft_printf("rra ");
            }
        }
        ft_push(stackb, size_b, stacka, size_a);
        ft_printf("pa ");
    }
}

void minimum_to_top(int *stacka, int *size_a)
{
    int i;
    int min;

    i = 0;
    min = find_smallest(stacka, size_a);
    if (min <= *size_a / 2)
    {
        while (min > 0)
        {
            ft_rotate(stacka, size_a);
            min--;
            ft_printf("ra ");
        }
    }
    else
    {
        min = *size_a - min;
        while (min > 0)
        {
            ft_reverse(stacka, size_a);
            min--;
            ft_printf("rra ");
        }
    }
}

void handle_rotations(t_cost cost_a, t_cost cost_b, int *stacka, int *size_a, int *stackb, int *size_b)
{
    // Perform synchronized rotations first
    while (cost_a.cost > 0 && cost_b.cost > 0)
    {
        if (cost_a.operation == 'u' && cost_b.operation == 'u')
        {
            ft_rotate(stacka, size_a);
            ft_rotate(stackb, size_b);
            ft_printf("rr ");  // Both stacks rotate up
            cost_a.cost--;
            cost_b.cost--;
        }
        else if (cost_a.operation == 'd' && cost_b.operation == 'd')
        {
            ft_reverse(stacka, size_a);
            ft_reverse(stackb, size_b);
            ft_printf("rrr ");  // Both stacks rotate down
            cost_a.cost--;
            cost_b.cost--;
        }
        else
        {
            break;  // Exit if the operations no longer match
        }
    }

    // Handle remaining rotations for stack A
    for (int i = 0; i < cost_a.cost; i++)
    {
        if (cost_a.operation == 'u')
        {
            ft_rotate(stacka, size_a);
            ft_printf("ra ");  // Rotate stack A up
        }
        else if (cost_a.operation == 'd')
        {
            ft_reverse(stacka, size_a);
            ft_printf("rra ");  // Rotate stack A down
        }
    }

    // Handle remaining rotations for stack B
    for (int i = 0; i < cost_b.cost; i++)
    {
        if (cost_b.operation == 'u')
        {
            ft_rotate(stackb, size_b);
            ft_printf("rb ");  // Rotate stack B up
        }
        else if (cost_b.operation == 'd')
        {
            ft_reverse(stackb, size_b);
            ft_printf("rrb ");  // Rotate stack B down
        }
    }
}

void sort_all(int *stacka, int *size_a, int *stackb, int *size_b)
{
    int cheap;

    ft_push(stacka, size_a, stackb, size_b);
    ft_printf("pb ");
    ft_push(stacka, size_a, stackb, size_b);
    ft_printf("pb ");
    while (*size_a > 3)
    {
        cheap = find_cheapest(stacka, size_a, stackb, size_b);

        t_cost cost_a = calculate_cost_for_stack_a(cheap, size_a);
        t_cost cost_b = calculate_cost_for_stack_b(stacka[cheap], stackb, size_b);

		handle_rotations(cost_a, cost_b, stacka, size_a, stackb, size_b);

        ft_push(stacka, size_a, stackb, size_b);
		ft_printf("pb ");
    }
 	sort_3(stacka, size_a);
    push_to_stack_a(stacka, size_a, stackb, size_b);
	minimum_to_top(stacka, size_a);
}
