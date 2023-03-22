/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   028.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:14:19 by arabenst          #+#    #+#             */
/*   Updated: 2023/03/22 08:11:16 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

unsigned long long	ft_sum_of_numbers_on_diagonals_in_spiral(int spiral_size)
{
	unsigned long long	sum;
	int					i;
	int					interval;

	sum = 0;
	i = 1;
	interval = 2;
	while (i <= spiral_size * spiral_size)
	{
		sum += i;
		i += interval;
		if (ft_sqrt(i) != -1)
			interval += 2;
	}
	return (sum);
}

int	main(void)
{
	printf("%lld\n", ft_sum_of_numbers_on_diagonals_in_spiral(1001));
}
