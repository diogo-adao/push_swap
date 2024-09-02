/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:37:07 by diolivei          #+#    #+#             */
/*   Updated: 2024/08/28 16:17:57 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	push_swap(int *stacka, int *size_a, int *stackb, int *size_b)
{
	if (is_sorted(stacka, size_a))
		return ;
	if (*size_a == 2)
		sort_2(stacka, size_a);
	if (*size_a == 3)
	{
		print_sort_3(stacka, size_a);
		sort_3(stacka, size_a);
	}
}

int	is_error(char *arg, int *stacka, int size)
{
	int	i;
	int	overflow;
	int	n;

	i = 0;
	overflow = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!arg[i])
		return (1);
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	n = ft_atoi(arg, &overflow);
	if (overflow)
		return (1);
	if (is_duplicate(stacka, size, n))
		return (1);
	return (0);
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
	}
	free (stacka);
	free (stackb);
	return (0);
}
