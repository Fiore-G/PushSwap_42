/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figarcia <figarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:45:07 by figarcia          #+#    #+#             */
/*   Updated: 2025/02/15 20:26:57 by figarcia         ###   ########.fr       */
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
		if (stack->value < stack->next->value)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

t_stack	*stack_find_max(t_stack *stack)
{
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max_node = stack;
	while (stack)
	{
		if (stack->value > stack->next->value)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

void	stack_index(t_stack *stack)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = stack;
	while (temp)
	{
		temp->index = i++;
		temp = temp->next;
	}
}
