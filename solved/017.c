/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   017.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:20:37 by arabenst          #+#    #+#             */
/*   Updated: 2023/02/23 15:59:52 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_get_count(int n)
{
	if (n == 1 || n == 2 || n == 6 || n == 10)
		return (3);//one two six ten
	if (n == 4 || n == 5 || n == 9)
		return (4);//four five nine
	if (n == 3 || n == 7 || n == 8 || n == 40 || n == 50 || n == 60)
		return (5);//three seven eight fouty fifty sixty
	if (n == 11 || n == 12 || n == 20 || n == 30 || n == 80 || n == 90)
		return (6);//eleven twelve twenty thirty eighty ninety
	if (n == 15 || n == 16 || n == 70 || n == 100)
		return (7);//fifteen sixteen seventy hundred 
	if (n == 13 || n == 14 || n == 18 || n == 19 || n == 1000)
		return (8);//thirteen fourteen eighteen nineteen thousand
	if (n == 17)
		return (9);//seventeen
	return (0);
}

int	ft_letter_count(int n)
{
	int	count;
	int	check;

	count = 0;
	check = 1000;
	if (n > 100 && n % 100 != 0)
		count += 3;
	while (n > 0 && check > 0)
	{
		if (n / check != 0)
		{
			// printf("count: %2d n: %4d check: %4d\n", count, n, check);
			if (n > 20 && n < 100 && n % 10 != 0)
				return (count + ft_get_count(n - n % check)
					+ ft_get_count(n % check));
			else if (n < 20 || (n > 10 && n / 10 < 10))
				return (count + ft_get_count(n));
			else
				count += ft_get_count(check) + ft_get_count(n / check);
			n = n % check;
		}
		check /= 10;
	}
	// printf("count: %2d n: %4d check: %4d\n", count, n, check);
	return (count);
}

int	ft_letter_count_up_to(int max)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (++i <= max)
	{
		sum += ft_letter_count(i);
		// printf("i=%-4d\tc=%-4d\n", i, ft_letter_count(i));
	}
	return (sum);
}

int	main(int argc, char **argv)
{
	printf("%d\n", ft_letter_count_up_to(1000));
}
