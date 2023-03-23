/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   003.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:17:57 by arabenst          #+#    #+#             */
/*   Updated: 2023/02/16 13:30:25 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long long	ft_largest_prime_factor(long long n)
{
	int	count;

	count = 1;
	while (n > 1)
	{
		count++;
		while (n % count == 0)
			n /= count;
	}
	return (count);
}

int	main(void)
{
	printf("%lld\n", ft_largest_prime_factor(600851475143));
}
