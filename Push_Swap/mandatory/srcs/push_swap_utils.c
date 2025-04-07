/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figarcia <figarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:56:42 by figarcia          #+#    #+#             */
/*   Updated: 2025/02/11 20:43:49 by figarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(EXIT_FAILURE);
}

void	check_valid_input(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		str++;
	}
	return (1);
}

void	check_duplicates(t_stack *stack)
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
				ft_error();
			temp = temp->next;
		}
		current = current->next;
	}
}

t_stack	*parse_input(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		check_valid_input(argv[i]);
		stack_add_back(&stack, stack_new(ft_atoi(argv[i])));
	}
	check_duplicates(stack);
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
}
