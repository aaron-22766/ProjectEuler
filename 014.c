/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   014.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 08:47:14 by arabenst          #+#    #+#             */
/*   Updated: 2023/02/22 09:07:31 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_longest_collatz_sequence(int threshold)
{
	int			start;
	long long	n;
	int			result;
	int			count;
	int			max;

	start = threshold - 1;
	max = 0;
	while (start > 0)
	{
		count = 0;
		n = start;
		while (n > 1)
		{
			if (n % 2 == 0)
				n /= 2;
			else
				n = 3 * n + 1;
			count++;
		}
		if (++count > max)
		{
			max = count;
			result = start;
		}
		start--;
	}
	return (result);
}

int	main(void)
{
	printf("%d\n", ft_longest_collatz_sequence(1000000));
}
