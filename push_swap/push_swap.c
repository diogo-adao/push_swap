/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:37:07 by diolivei          #+#    #+#             */
/*   Updated: 2024/08/08 19:31:36 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void push_swap(int *stacka, int *size_a, int *stackb, int *size_b)
{
	//ft_swap(&stacka[0], &stacka[1], size_a);
	//ft_push(stacka, size_a, stackb, size_b);
	//ft_rotate(stacka, size_a);
	//ft_reverse(stacka, size_a);
}

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		int size = argc - 1;
		int stacka[size];
		int stackb[size];
		int size_a = size;
		int size_b = 0;

		int i = 0;
		while (i < size)
		{
			stacka[i] = ft_atoi(argv[i + 1]);
			i++;
		}
		push_swap(stacka, &size_a, stackb, &size_b);
		i = 0;
		ft_printf("stack A:\n");
		while (i < size_a)
		{
			ft_printf("%d\n", stacka[i]);
			i++;
		}
		i = 0;
		ft_printf("stack B:\n");
		while (i < size_b)
		{
			ft_printf("%d\n", stackb[i]);
			i++;
		}
	} else
		write(2, "Error\n", 6);
	return (0);
}
