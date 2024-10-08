/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diolivei <diolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:11:42 by diolivei          #+#    #+#             */
/*   Updated: 2024/10/01 18:15:25 by diolivei         ###   ########.fr       */
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

#endif
