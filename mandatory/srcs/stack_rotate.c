/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figarcia <figarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:21:35 by figarcia          #+#    #+#             */
/*   Updated: 2025/02/22 19:47:04 by figarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_stack(t_stack **stack, char stack_name)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = stack_last(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
	if (stack_name == 'a')
		ft_printf("ra\n");
	else if (stack_name == 'b')
		ft_printf("rb\n");
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate_stack(stack_a, 'a');
	rotate_stack(stack_b, 'b');
	ft_printf("rr\n");
}

void	rev_rotate_stack(t_stack **stack, char stack_name)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = stack_last(*stack);
	second_last = *stack;
	while (second_last->next != last)
		second_last = second_last->next;
	last->next = *stack;
	*stack = last;
	second_last->next = NULL;
	if (stack_name == 'a')
		ft_printf("rra\n");
	else if (stack_name == 'b')
		ft_printf("rrb\n");
}

void	rev_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate_stack(stack_a, 'a');
	rev_rotate_stack(stack_b, 'b');
	ft_printf("rrr\n");
}