/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   023.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:35:12 by arabenst          #+#    #+#             */
/*   Updated: 2023/03/09 09:52:14 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_div_sum(int n)
{
	int	div_sum;
	int	i;

	div_sum = 0;
	i = 1;
	while (i <= n / 2)
	{
		if (n % i == 0)
			div_sum += i;
		i++;
	}
	return (div_sum);
}

int	ft_is_abundant(int n)
{
	if (ft_div_sum(n) > n)
		return (1);
	return (0);
}

char	*ft_get_abundant(void)
{
	char	*abundant;
	int		i;

	abundant = calloc(28123, sizeof(char));
	if (!abundant)
		return (NULL);
	i = -1;
	while (++i < 28123)
		abundant[i] = ft_is_abundant(i);
	return (abundant);
}

int	ft_sum_of_not_sum_of_abundant(void)
{
	char	*abundant;
	int		i;
	int		j;
	int		sum;
	int		can;

	abundant = ft_get_abundant();
	if (!abundant)
		return (-1);
	sum = 0;
	i = 0;
	while (++i <= 28123)
	{
		j = 12 - 1;
		can = 0;
		while (can == 0 && ++j <= i / 2)
			if (abundant[j] && abundant[i - j])
				can = 1;
		if (can == 0)
			sum += i;
	}
	free(abundant);
	return (sum);
}

int	main(void)
{
	printf("%d\n", ft_sum_of_not_sum_of_abundant());
}
