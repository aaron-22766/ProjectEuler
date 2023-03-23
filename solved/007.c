/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   007.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:12:14 by arabenst          #+#    #+#             */
/*   Updated: 2023/02/17 12:45:14 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	div;

	div = 2;
	if (nb < 2)
		return (0);
	while (div <= nb / div)
	{
		if (nb % div == 0)
			return (0);
		div++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	nb++;
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}

int	ft_nth_prime(int n)
{
	int	i;
	int	prime;

	i = 0;
	prime = 1;
	while (i < n)
	{
		prime = ft_find_next_prime(prime);
		i++;
	}
	return (prime);
}

int	main(void)
{
	printf("%d\n", ft_nth_prime(10001));
}
