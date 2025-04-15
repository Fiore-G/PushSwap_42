/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figarcia <figarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:30:57 by figarcia          #+#    #+#             */
/*   Updated: 2025/02/11 15:37:48 by figarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

typedef struct s_stack
{
	int		value;
	int		index;
	struct s_stack	*next;
}	t_stack;

void	push_swap(int argc, int **argv);
void	swap_stack(t_stack **stack, char stack_name);
void	swap_both(t_stack **stack_a, t_stack **stack_b);
void	push_to_stack(t_stack **src_stack, t_stack **dest_stack, char dest);
void	rotate_stack(t_stack **stack, char stack_name);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);
void	rev_rotate_stack(t_stack **stack, char stack_name);
void	rev_rotate_both(t_stack **stack_a, t_stack **stack_b);
t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new_node);
t_stack	*stack_last(t_stack *stack);
int		stack_size(t_stack *stack);
int		get_max_value(t_stack *stack);
void	sort_small_stack(t_stack **a, t_stack **b, int size);
void	radix_sort(t_stack **a, t_stack **b);
void	ft_error(void);
t_stack	*parse_input(int argc, char **argv);
void	free_stack(t_stack **stack);
int		stack_is_sorted(t_stack *stack);
t_stack	*stack_find_min(t_stack *stack);

#endif