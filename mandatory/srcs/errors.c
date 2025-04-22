/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: figarcia <figarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:26:39 by figarcia          #+#    #+#             */
/*   Updated: 2025/04/17 20:55:40 by figarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	is_sign_only(char *str)
{
	if ((str[0] == '+' || str[0] == '-') && str[1] == '\0')
		return (1);
	return (0);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	validate_and_convert(char *str, int *result)
{
	long	num;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	if (!str || *str == '\0' || is_sign_only(str) || !is_valid_number(str))
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	num = 0;
	while (str[i])
	{
		num = num * 10 + (str[i++] - '0');
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			return (0);
	}
	*result = (int)(num * sign);
	return (1);
}
