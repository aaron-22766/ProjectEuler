/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   027.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:14:19 by arabenst          #+#    #+#             */
/*   Updated: 2023/03/21 09:40:31 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_quadratic_primes(int a_max, int b_max)
{
	int	product;
	int	max_prime_amount;
	int	a;
	int	b;
	int	n;

	max_prime_amount = 0;
	a = -a_max + 1;
	while (a < a_max)
	{
		b = -b_max + 1;
		while (b < b_max)
		{
			n = 0;
			while (ft_is_prime(ft_pow(n, 2) + a * n + b))
				n++;
			if (n > max_prime_amount)
			{
				max_prime_amount = n;
				product = a * b;
			}
			b++;
		}
		a++;
	}
	return (product);
}

int	main(void)
{
	ft_printf("%d\n", ft_quadratic_primes(1000, 1001));
}
