/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figarcia <figarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 20:44:15 by figarcia          #+#    #+#             */
/*   Updated: 2025/04/15 11:13:15 by figarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_stack(t_stack **stack, char stack_name)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	if (stack_name == 'a')
		ft_printf("sa\n");
	else if (stack_name == 'b')
		ft_printf("sb\n");
}

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	swap_stack(stack_a, 'a');
	swap_stack(stack_b, 'b');
	ft_printf("ss\n");
}

void	push_to_stack(t_stack **src_stack, t_stack **dest_stack, char dest)
{
	t_stack	*tmp;

	if (!*src_stack)
		return ;
	tmp = (*src_stack)->next;
	(*src_stack)->next = *dest_stack;
	*dest_stack = *src_stack;
	*src_stack = tmp;
	if (dest == 'a')
		ft_printf("pa\n");
	else if (dest == 'b')
		ft_printf("pb\n");
}
