/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Even Fibonacci numbers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:44:45 by arabenst          #+#    #+#             */
/*   Updated: 2023/02/15 14:15:29 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long long	ft_even_fibonacci(long long sum, int a, int b, int max)
{
	if (a + b > max)
		return (sum);
	if (b == 0)
		b++;
	if ((a + b) % 2 == 0)
		sum += a + b;
	return (ft_fibonacci(sum, b, a + b, max));
}

int	main(void)
{
	printf("%lld\n", ft_even_fibonacci(0, 0, 0, 4000000));
}
