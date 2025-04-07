/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figarcia <figarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:44:15 by figarcia          #+#    #+#             */
/*   Updated: 2025/02/22 17:19:32 by figarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_stack(t_stack **stack_a, t_stack **stack_b, char stack_name)
{
	t_stack	**stack;
	t_stack	*tmp;

	if (stack_name == 'a')
	{
		stack = stack_a;
		ft_printf("sa\n");
	}
	else if (stack_name == 'b')
	{
		stack = stack_b;
		ft_printf("sb\n");
	}
	else
		return ;
	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	swap_stack(stack_a, stack_b, 'a');
	swap_stack(stack_a, stack_b, 'b');
	ft_printf("ss\n");
}

void	push_to_stack(t_stack **stack_a, t_stack **stack_b, char dest)
{
	t_stack	**src_stack;
	t_stack	**dest_stack;
	t_stack	*tmp;

	if (dest == 'a')
	{
		src_stack = stack_b;
		dest_stack = stack_a;
		ft_printf("pa\n");
	}
	else if (dest == 'b')
	{
		src_stack = stack_a;
		dest_stack = stack_b;
		ft_printf("pb\n");
	}
	else
		return ;
	if (!*src_stack)
		return ;
	tmp = (*src_stack)->next;
	(*src_stack)->next = *dest_stack;
	*dest_stack = *src_stack;
	*src_stack = tmp;
}
