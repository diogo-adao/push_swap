/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:37:07 by diolivei          #+#    #+#             */
/*   Updated: 2024/09/17 14:36:36 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap(int *stacka, int *size_a, int *stackb, int *size_b)
{
	if (!is_sorted(stacka, size_a))
	{
		if (*size_a == 2)
			sort_2(stacka, size_a);
		else if (*size_a == 3)
			sort_3(stacka, size_a);
		else
			sort_all(stacka, size_a, stackb, size_b);
	}
}

int	main(int argc, char *argv[])
{
	int	*stacka;
	int	*stackb;
	int	size_a;
	int	size_b;
	int	i;

	stacka = (int *)malloc((argc - 1) * sizeof(int));
	stackb = (int *)malloc((argc - 1) * sizeof(int));
	size_a = argc - 1;
	size_b = 0;
	i = 0;
	if (argc > 1)
	{
		while (i < argc - 1)
		{
			if (is_error(argv[i + 1], stacka, i))
				return (write(2, "Error\n", 6));
			stacka[i] = ft_atoi(argv[i + 1], NULL);
			i++;
		}
		push_swap(stacka, &size_a, stackb, &size_b);
	}
	free(stacka);
	free(stackb);
	return (0);
}
