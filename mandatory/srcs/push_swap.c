/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figarcia <figarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 20:49:25 by figarcia          #+#    #+#             */
/*   Updated: 2025/04/15 11:18:31 by figarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	if (argc < 2)
		return (0);
	a = parse_input(argc, argv);
	b = NULL;
	if (stack_is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	size = stack_size(a);
	if (size <= 5)
		sort_small_stack(&a, &b, size);
	else if (size <= 500)
		radix_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
