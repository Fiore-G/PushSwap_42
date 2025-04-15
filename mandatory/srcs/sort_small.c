/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figarcia <figarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:02:07 by figarcia          #+#    #+#             */
/*   Updated: 2025/02/11 20:44:18 by figarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		swap_stack(a, 'a');
}

void	sort_three(t_stack **a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*a)->value;
	middle = (*a)->next->value;
	bottom = (*a)->next->next->value;
	if (top > middle && middle > bottom)
	{
		swap_stack(a, 'a');
		rev_rotate_stack(a, 'a');
	}
	else if (top < middle && middle > bottom && top > bottom)
		rev_rotate_stack(a, 'a');
	else if (top > middle && middle < bottom && top > bottom)
		rotate_stack(a, 'a');
	else if (top < middle && middle > bottom && top < bottom)
	{
		swap_stack(a, 'a');
		rotate_stack(a, 'a');
	}
	else if (top > middle && middle < bottom && top < bottom)
		swap_stack(a, 'a');
}

void	sort_four_five(t_stack **a, t_stack **b, int size)
{
	int	elements_to_push;

	elements_to_push = size - 3;
	while (elements_to_push--)
	{
		if ((*a)->value == stack_find_min(*a)->value)
			push_to_stack(a, b, 'a');
		else
			rotate_stack(a, 'a');
	}
	sort_three(a);
	while (*b)
		push_to_stack(a, b, 'a');
}

void	sort_small_stack(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4 || size == 5)
		sort_four_five(a, b, size);
	else
		ft_error();
}