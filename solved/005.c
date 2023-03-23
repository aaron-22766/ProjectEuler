/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   005.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:02:12 by arabenst          #+#    #+#             */
/*   Updated: 2023/02/16 16:08:00 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long long	ft_all_modulo(long long n, int max)
{
	int	i;

	i = 1;
	while (i <= max)
	{
		if (n % i != 0)
			return (0);
		i++;
	}
	return (1);
}

long long	ft_smallest_multiple(int max)
{
	long long	n;

	n = 1;
	while (ft_all_modulo(n, max) == 0)
		n++;
	return (n);
}

int	main(void)
{
	printf("%lld\n", ft_smallest_multiple(20));
}
