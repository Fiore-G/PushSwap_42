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
		sa(a);
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
		sa(a);
		rra(a);
	}
	else if (top < middle && middle > bottom && top > bottom)
		rra(a);
	else if (top > middle && middle < bottom && top > bottom)
		ra(a);
	else if (top < middle && middle > bottom && top < bottom)
	{
		sa(a);
		ra(a);
	}
	else if (top > middle && middle < bottom && top < bottom)
		sa(a);
}

void	sort_four_five(t_stack **a, t_stack **b, int size)
{
	int	elements_to_push;

	elements_to_push = size - 3;
	while (elements_to_push--)
	{
		if ((*a)->value == stack_min(*a))
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
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
