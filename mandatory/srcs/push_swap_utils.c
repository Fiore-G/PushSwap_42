/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figarcia <figarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:56:42 by figarcia          #+#    #+#             */
/*   Updated: 2025/04/16 21:09:08 by figarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*temp;

	current = stack;
	while (current)
	{
		temp = current->next;
		while (temp)
		{
			if (current->value == temp->value)
			{
				free_stack(&stack);
				ft_error();
				return (0);
			}
			temp = temp->next;
		}
		current = current->next;
	}
	return (1);
}

t_stack	*parse_input(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	int		num;

	stack = NULL;
	if (argc <= 1)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (!validate_and_convert(argv[i], &num))
		{
			free_stack(&stack);
			ft_error();
		}
		stack_add_back(&stack, stack_new(num));
		i++;
	}
	if (!check_duplicates(stack))
	{
		free_stack(&stack);
		ft_error();
	}
	return (stack);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}
