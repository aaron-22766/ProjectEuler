/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   030.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:14:19 by arabenst          #+#    #+#             */
/*   Updated: 2023/03/23 12:18:58 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_digit_power_sum(int exponent, int check)
{
	int	digit;
	int	result;

	result = 0;
	digit = ft_count_digits(check);
	while (--digit >= 0)
	{
		result += ft_pow(check / ft_pow(10, digit), exponent);
		check -= (check / ft_pow(10, digit)) * ft_pow(10, digit);
	}
	return (result);
}

int	ft_sum_of_digit_powers(int exponent)
{
	int	sum;
	int	check;

	sum = 0;
	check = 11;
	while (check < 10000000)
	{
		if (ft_digit_power_sum(exponent, check) == check)
			sum += check;
		check++;
	}
	return (sum);
}

int	main(void)
{
	ft_printf("%d\n", ft_sum_of_digit_powers(5));
}
