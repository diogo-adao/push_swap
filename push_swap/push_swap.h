#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// Operations
void	ft_swap(int *n1, int *n2, int *size);
void	ft_push(int *stack1, int *size_1, int *stack2, int *size_2);
void	ft_rotate(int *stack, int *size);
void	ft_reverse(int *stack, int *size);

// Handlers
int     is_error(char *arg, int *stacka, int size);
int		is_sorted(int *stack, int *size);

// Algorithms
void	sort_2(int *stack, int *size);
void	sort_3(int *stack, int *size);
void    sort_all(int *stacka, int *size_a, int *stackb, int *size_b);

#endif