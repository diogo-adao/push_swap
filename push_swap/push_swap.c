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

void push_swap(int *stacka, int *stackb)
{
	//ft_swap(&stacka[0], &stacka[1]);
}

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		int size = 1;
		while (argv[size])
			size++;
		int stacka[size - 1];
		int stackb[size - 1];
		stackb[0] = '\0';

		int i = 0;
		while (i < size - 1)
		{
			stacka[i] = ft_atoi(argv[i + 1]);
			i++;
		}
		push_swap(stacka, stackb);
		i = 0;
		ft_printf("stack A:\n");
		while (stacka[i])
		{
			ft_printf("%d\n", stacka[i]);
			i++;
		}
		i = 0;
		ft_printf("stack B:\n");
		while (stackb[i])
		{
			ft_printf("%d\n", stackb[i]);
			i++;
		}
	} else
		write(2, "Error\n", 6);
	return (0);
}
