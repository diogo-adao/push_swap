/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:43:43 by diolivei          #+#    #+#             */
/*   Updated: 2024/08/08 18:58:18 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void ft_swap(int *n1, int *n2, int *size)
{
	if (*size > 1)
	{
		int tmp;

		tmp = *n1;
		*n1 = *n2;
		*n2 = tmp;
	}
}

void	ft_push(int *stack1, int *size_1, int *stack2, int *size_2)
{
	if (*size_1 > 0)
	{
		int i = *size_2;

		while (i > 0)
		{
			stack2[i] = stack2[i - 1];
			i--;
		}
		stack2[0] = stack1[0];
		(*size_2)++;

		i = 0;
		while (i < *size_1 - 1)
		{
			stack1[i] = stack1[i + 1];
			i++;
		}
		(*size_1)--;
	}
}
