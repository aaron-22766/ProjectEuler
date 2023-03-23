/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   016.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:07:51 by arabenst          #+#    #+#             */
/*   Updated: 2023/02/23 10:03:04 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_multiply(int n, int power[], int power_size)
{
	int	carry;
	int	i;
	int	prod;

	carry = 0;
	i = -1;
	while (++i < power_size)
	{
		prod = power[i] * n + carry;
		power[i] = prod % 10;
		carry = prod / 10;
	}
	while (carry)
	{
		power[power_size] = carry % 10;
		carry /= 10;
		power_size++;
	}
	return (power_size);
}

int	ft_power_digit_sum(int n, int exponent)
{
	int	power[1000];
	int	power_size;
	int	temp;
	int	i;
	int	sum;

	if (exponent == 0)
		return (n);
	temp = n;
	power_size = 0;
	while (temp != 0)
	{
		power[power_size++] = temp % 10;
		temp /= 10;
	}
	i = 1;
	while (++i <= exponent)
		power_size = ft_multiply(n, power, power_size);
	sum = 0;
	while (--power_size >= 0)
		sum += power[power_size];
	return (sum);
}

int	main(void)
{
	printf("%d\n", ft_power_digit_sum(2, 1000));
}
