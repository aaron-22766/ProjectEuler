/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   006.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:09:33 by arabenst          #+#    #+#             */
/*   Updated: 2023/02/16 16:16:29 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long long	ft_sum_square(int max)
{
	long long	result;
	int			i;

	result = 0;
	i = 1;
	while (i <= max)
	{
		result += i * i;
		i++;
	}
	return (result);
}

long long	ft_square_sum(int max)
{
	long long	result;
	int			i;

	result = 0;
	i = 1;
	while (i <= max)
	{
		result += i;
		i++;
	}
	return (result * result);
}

long long	ft_sum_square_difference(int max)
{
	long long	sum_square;
	long long	square_sum;

	sum_square = ft_sum_square(max);
	square_sum = ft_square_sum(max);
	if (sum_square > square_sum)
		return (sum_square - square_sum);
	return (square_sum - sum_square);
}

int	main(void)
{
	printf("%lld\n", ft_sum_square_difference(100));
}
