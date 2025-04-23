/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figarcia <figarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:45:07 by figarcia          #+#    #+#             */
/*   Updated: 2025/04/22 20:15:55 by figarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*stack_find_min(t_stack *stack)
{
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	while (stack)
	{
		if (stack->value < min_node->value)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

void	stack_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*tmp_node;

	current = stack;
	while (current)
	{
		current->index = 0;
		tmp_node = stack;
		while (tmp_node)
		{
			if (current->value > tmp_node->value)
				current->index++;
			tmp_node = tmp_node->next;
		}
		current = current->next;
	}
}

int	get_position(t_stack *stack, t_stack *node)
{
	int		pos;
	t_stack	*temp;

	pos = 0;
	temp = stack;
	while (temp != node)
	{
		pos++;
		temp = temp->next;
	}
	return (pos);
}
