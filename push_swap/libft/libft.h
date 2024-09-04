/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:11:42 by diolivei          #+#    #+#             */
/*   Updated: 2024/09/04 15:39:31 by diolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

int		ft_atoi(const char *str, int *overflow);

// ---------- PRINTF -------------
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr(long n, int base);
int		ft_putupper(unsigned int n, int base);
int		ft_putpointer(unsigned long n, int base);
int		ft_printf(const char *format, ...);

// ----------- PUSH_SWAP -------------
void	ft_swap(int *n1, int *n2, int *size);
void	ft_push(int *stack1, int *size_1, int *stack2, int *size_2);
void	ft_rotate(int *stack, int *size);
void	ft_reverse(int *stack, int *size);
int		is_duplicate(int *arr, int size, int n);
int		is_sorted(int *stack, int *size);
void	sort_3(int *stack, int *size);
void	sort_2(int *stack, int *size);

#endif
