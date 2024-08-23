/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:46:31 by diolivei          #+#    #+#             */
/*   Updated: 2024/04/26 17:46:38 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str, int *overflow)
{
	int		res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == '\v' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
    	if (sign == 1 && res > (INT_MAX - (str[i] - '0')) / 10)
    	{
        	*overflow = 1;
			return (INT_MAX);
		}
		else if (sign == -1 && res > (2147483648 - (str[i] - '0')) / 10)
		{
			*overflow = 1;
			return (INT_MIN);
		}
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}
