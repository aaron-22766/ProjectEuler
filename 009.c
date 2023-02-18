/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   009.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:37:46 by arabenst          #+#    #+#             */
/*   Updated: 2023/02/18 16:13:11 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_special_pythagorean_triplet(int sum)
{
	int	a;
	int	b;
	int	c;

	a = 1;
	while (a <= sum)
	{
		b = 1;
		while (b <= sum)
		{
			c = 1;
			while (c <= sum)
			{
				if (a + b + c == sum && (a * a) + (b * b) == (c * c))
				{
					printf("a=%d, b=%d, c=%d\n", a, b, c);
					return (a * b * c);
				}
				c++;
			}
			b++;
		}
		a++;
	}
	return (0);
}

int	main(void)
{
	printf("%d\n", ft_special_pythagorean_triplet(1000));
}
