/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figarcia <figarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:02:07 by figarcia          #+#    #+#             */
/*   Updated: 2025/04/22 20:15:13 by figarcia         ###   ########.fr       */
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

void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*min_node;
	t_stack	*tmp;
	int		min_pos;

	min_node = stack_find_min(*a);
	min_pos = 0;
	tmp = *a;
	while (tmp != min_node)
	{
		min_pos++;
		tmp = tmp->next;
	}
	if (min_pos <= 2)
	{
		while ((*a)->value != min_node->value)
			rotate_stack(a, 'a');
	}
	else
	{
		while ((*a)->value != min_node->value)
			rev_rotate_stack(a, 'a');
	}
	push_to_stack(a, b, 'b');
	sort_three(a);
	push_to_stack(b, a, 'a');
}

void	sort_five(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*min_node;

	i = 0;
	while (i < 2)
	{
		min_node = stack_find_min(*a);
		while ((*a)->value != min_node->value)
		{
			if (get_position(*a, min_node) <= stack_size(*a) / 2)
				rotate_stack(a, 'a');
			else
				rev_rotate_stack(a, 'a');
		}
		push_to_stack(a, b, 'b');
		i++;
	}
	sort_three(a);
	push_to_stack(b, a, 'a');
	push_to_stack(b, a, 'a');
}

void	sort_small_stack(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else
		ft_error();
}
