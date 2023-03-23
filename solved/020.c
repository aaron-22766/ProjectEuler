/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   020.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 08:49:46 by arabenst          #+#    #+#             */
/*   Updated: 2023/03/06 11:37:40 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

char	*ft_large_multiply(char *num1, char *num2)
{
	char	*product;
	int		i;
	int		j;
	int		carry;

	product = calloc(strlen(num1) + strlen(num2) + 1, sizeof(char));
	if (!product)
		return (NULL);
	memset(product, '0', strlen(num1) + strlen(num2));
	i = -1;
	while (num1[++i])
	{
		carry = 0;
		j = -1;
		while (num2[++j])
		{
			carry += (num1[i] - '0') * (num2[j] - '0') + (product[i + j] - '0');
			product[i + j] = carry % 10 + '0';
			carry /= 10;
		}
		product[i + j] += carry;
	}
	return (product);
}

char	*ft_large_decrement(char *a)
{
	char	*result;
	int		i;
	int		j;

	result = strdup(a);
	i = -1;
	while (result[++i] == '0')
		result[i] = '9';
	if (result[i] > '0')
		result[i]--;
	if (result[i] <= '0' && !result[i + 1])
		result[i] = 0;
	return (result);
}

char	*ft_large_factorial(char *n)
{
	if (n[1] == 0 && n[0] == '1')
		return (n);
	return (ft_large_multiply(n, ft_large_factorial(ft_large_decrement(n))));
}

char	ft_count_digits(int n)
{
	char	count;

	count = 1;
	while (n / 10 > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_sum_of_digits_of_factorial(int n)
{
	int		sum;
	char	*num;
	int		i;
	int		j;

	num = calloc(ft_count_digits(n) + 1, sizeof(char));
	if (!num)
		return (-1);
	i = 0;
	while (n > 0)
	{
		num[i++] = '0' + n % 10;
		n /= 10;
	}
	num = ft_large_factorial(num);
	sum = 0;
	i = -1;
	while (num[++i])
		sum += num[i] - '0';
	return (sum);
}

int	main(void)
{
	printf("%d\n", ft_sum_of_digits_of_factorial(100));
}
