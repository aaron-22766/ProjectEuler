/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   012.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 08:15:09 by arabenst          #+#    #+#             */
/*   Updated: 2023/02/21 09:25:34 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_count_divisors(long long n)
{
	int	count;
	int	div;

	count = 0;
	div = 1;
	while (div <= n / div)
	{
		if (n % div == 0)
			count++;
		div++;
	}
	return (count * (1 + (n > 1)));
}

long long	ft_first_triangle_number(int divisors)
{
	long long	triangle;
	int			i;

	triangle = 1;
	i = 2;
	while (ft_count_divisors(triangle) <= divisors)
		triangle += i++;
	return (triangle);
}

int	main(void)
{
	printf("%lld\n", ft_first_triangle_number(500));
}
