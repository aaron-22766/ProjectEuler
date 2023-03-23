/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   004.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:31:03 by arabenst          #+#    #+#             */
/*   Updated: 2023/02/16 14:37:14 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_palindrome(int n)
{
	int	start;
	int	end;

	start = 1;
	while (start * 10 <= n)
		start *= 10;
	end = 1;
	while (start >= end)
	{
		if ((n / start) % 10 != (n / end) % 10)
			return (0);
		start /= 10;
		end *= 10;
	}
	return (1);
}

long long	ft_find_largest_palindrome(int digit)
{
	int	a;
	int	b;
	int	i;
	int	max;

	a = 1;
	while (i < digit)
	{
		i++;
		a *= 10;
	}
	a--;
	b = a;
	max = 0;
	while (a >= 2)
	{
		if (a * b > max && (ft_is_palindrome(a * b)))
			max = a * b;
		if (b == 2)
		{
			a--;
			b = a;
		}
		else
			b--;
	}
	printf("%d * %d\n", a, b);
	return (max);
}

int	main(void)
{
	printf("%lld\n", ft_find_largest_palindrome(3));
}
