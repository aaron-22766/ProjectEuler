/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   024.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 08:36:58 by arabenst          #+#    #+#             */
/*   Updated: 2023/03/13 16:01:05 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"

int	ft_factorial(int n)
{
	if (n == 0)
		return (1);
	return (n * ft_factorial(n - 1));
}

int	*ft_lehmer_code(int n, int size)
{
	int	*result;
	int	i;

	result = calloc(size, sizeof(int));
	if (!result)
		return (NULL);
	i = 0;
	while (ft_factorial(i) <= n)
		i++;
	while (n > 0)
	{
		result[size - i] = n / ft_factorial(i - 1);
		n = n % ft_factorial(--i);
	}
	// i = -1;
	// while (++i < size)
	// 	printf("%d, ", result[i]);
	// printf("\n");
	return (result);
}

char	*ft_make_sorted(const char *str)
{
	char	*sorted;
	char	temp;
	int		i;
	int		j;
	int		s;

	sorted = calloc(strlen(str) + 1, sizeof(char));
	if (!sorted)
		return (NULL);
	ft_strlcpy(sorted, str, strlen(str) + 1);
	i = -1;
	while (sorted[++i + 1])
	{
		j = i;
		while (sorted[++j])
		{
			if (sorted[i] > sorted[j])
			{
				temp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = temp;
			}
		}
	}
	return (sorted);
}

char	*ft_get_nth_lexicographic_permutaion(char *perm, int nth)
{
	char	*current;
	char	*result;
	int		*lc;
	int		i;
	int		r;

	if (nth < 1 || nth > ft_factorial(strlen(perm)))
		return (NULL);
	result = calloc(strlen(perm) + 1, sizeof(char));
	if (!result)
		return (NULL);
	current = ft_make_sorted(perm);
	if (!current)
		return (free(result), NULL);
	lc = ft_lehmer_code(nth - 1, strlen(perm));
	if (!lc)
		return (free(current), free(result), NULL);
	i = -1;
	while (++i < strlen(perm))
	{
		result[i] = current[lc[i]];
		while (current[++lc[i] - 1])
			current[lc[i] - 1] = current[lc[i]];
	}
	return (free(current), free(lc), result);
}

int	main(void)
{
	printf("%s\n", ft_get_nth_lexicographic_permutaion("0123456789", 1000000));
}
