/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   010.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:55:45 by arabenst          #+#    #+#             */
/*   Updated: 2023/02/20 09:03:19 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int n)
{
	int	div;

	div = 2;
	while (div <= n / div)
	{
		if (n % div == 0)
			return (0);
		div++;
	}
	return (1);
}

long long	ft_sum_of_primes(int max)
{
	long long	sum;
	int			i;

	sum = 0;
	i = 2;
	while (i < max)
	{
		if (ft_is_prime(i))
			sum += i;
		i++;
	}
	return (sum);
}

int	main(void)
{
	printf("%lld\n", ft_sum_of_primes(2000000));
}
