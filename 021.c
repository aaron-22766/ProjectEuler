/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   021.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 07:33:55 by arabenst          #+#    #+#             */
/*   Updated: 2023/03/07 07:53:09 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_amicable_number(int n)
{
	int	div_sum;
	int	i;

	div_sum = 0;
	i = 1;
	while (i < n / i)
	{
		if (n % i == 0)
			div_sum += i + (i != 1) * (n / i);
		i++;
	}
	if (div_sum == n)
		return (0);
	i = 1;
	while (i < div_sum / i)
	{
		if (div_sum % i == 0)
			n -= i + (i != 1) * (div_sum / i);
		i++;
	}
	return (!n);
}

int	ft_sum_of_amicable_numbers(int up_to)
{
	int	i;
	int	sum;

	sum = 0;
	i = 1;
	while (++i < up_to)
		if (ft_is_amicable_number(i))
			sum += i;
	return (sum);
}

int	main(void)
{
	printf("%d\n", ft_sum_of_amicable_numbers(10000));
}
