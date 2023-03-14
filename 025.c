/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   025.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:22:24 by arabenst          #+#    #+#             */
/*   Updated: 2023/03/14 09:39:52 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	*ft_str_addition(char *a, char *b)
{
	char	*temp;
	char	*sum;
	int		i;

	if (ft_strlen(a) < ft_strlen(b))
	{
		temp = a;
		a = b;
		b = temp;
	}
	sum = ft_calloc(ft_strlen(a) + 2, sizeof(char));
	if (!sum)
		return (NULL);
	ft_memset(sum, '0', ft_strlen(a) + 1);
	i = -1;
	while (a[++i])
	{
		if (i >= ft_strlen(b))
			sum[i] += a[i] - '0';
		else
		{
			sum[i] += (a[i] - '0' + b[i] - '0') % 10;
			sum[i + 1] += (a[i] - '0' + b[i] - '0') / 10;
		}
	}
	i = ft_strlen(sum) - 1;
	while (sum[i] == '0')
		sum[i--] = 0;
	return (sum);
}

unsigned long	ft_get_first_index_of_fibonacci_with_n_digits(int n)
{
	unsigned long	index;
	char			*a;
	char			*b;
	char			*temp;

	if (n < 1)
		return (-1);
	if (n == 1)
		return (1);
	a = ft_itoa(1);
	b = ft_itoa(1);
	index = 2;
	while (ft_strlen(b) < n)
	{
		temp = ft_str_addition(a, b);
		free(a);
		a = b;
		b = temp;
		index++;
	}
	free(a);
	free(b);
	return (index);
}

int	main(void)
{
	ft_printf("%d\n", ft_get_first_index_of_fibonacci_with_n_digits(1000));
}
