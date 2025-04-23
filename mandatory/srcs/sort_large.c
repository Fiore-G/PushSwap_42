/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figarcia <figarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:46:38 by figarcia          #+#    #+#             */
/*   Updated: 2025/04/22 20:13:29 by figarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_max_bits(t_stack *stack)
{
	int	max;
	int	bits;

	max = 0;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	bit_count;
	int	i;
	int	j;
	int	size;

	stack_index(*a);
	bit_count = get_max_bits(*a);
	i = 0;
	while (i < bit_count)
	{
		size = stack_size(*a);
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				rotate_stack(a, 'a');
			else
				push_to_stack(a, b, 'b');
			j++;
		}
		while (*b)
			push_to_stack(b, a, 'a');
		i++;
	}
}
