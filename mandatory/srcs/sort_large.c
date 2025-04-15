/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figarcia <figarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:46:38 by figarcia          #+#    #+#             */
/*   Updated: 2025/02/28 20:09:55 by figarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_max_bits(t_stack *stack)
{
	int	max;
	int	max_bits;

	max = get_max_value(stack);
	max_bits = 0;
	while (max >> max_bits)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;

	max_bits = get_max_bits(*a);
	size = stack_size(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->value >> i) & 1)
				rotate_stack(a, 'a');
			else
				push_to_stack(a, b, 'a');
			j++;
		}
		while (*b)
			push_to_stack(a, b, 'b');
		i++;
	}
} 