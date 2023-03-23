/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   026.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 07:59:58 by arabenst          #+#    #+#             */
/*   Updated: 2023/03/17 08:27:03 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_count_recurring_cycle_length_of_unit_fraction(int denominator)
{
	int	count;
	int	a;
	
	a = 1;
	count = 0;
	while (!count || a != 1)
	{
		a = (a * 10) % denominator;
		count++;
	}
	return (count);
}

int	ft_longest_recurring_cycle_in_unit_fraction(int top)
{
	int	max;
	int	result;
	int	temp;
	int	prime;

	prime = 6;
	max = 0;
	result = 0;
	while (prime < top)
	{
		prime = ft_find_next_prime(prime);
		temp = ft_count_recurring_cycle_length_of_unit_fraction(prime);
		if (max < temp)
		{
			result = prime;
			max = temp;
		}
	}
	return (result);
}

int	main(void)
{
	ft_printf("%d\n", ft_longest_recurring_cycle_in_unit_fraction(1000));
}
