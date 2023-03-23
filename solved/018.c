/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   018.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:37:38 by arabenst          #+#    #+#             */
/*   Updated: 2023/02/28 09:43:49 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 15

static int	ft_get_worth(int i, int j)
{
	if (i == 0 && j == 0)
		return 0;
	else if (i == j || j == 0)
		return 1;
	return (ft_get_worth(i - 1, j - 1) + ft_get_worth(i - 1, j));
}

int	ft_max_path_sum(int triangle[SIZE][SIZE])
{
	int	***sums;
	int	max;
	int	size;
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	max = 0;
	sums = calloc(SIZE, sizeof(int **));
	if (!sums)
		return (-1);
	while (i < SIZE)
	{
		sums[i] = calloc(i + 1, sizeof(int *));
		if (!sums[i])
			return (-1);
		j = 0;
		while (j < i + 1)
		{
			size = ft_get_worth(i, j) + (i + j == 0) + 1;
			sums[i][j] = calloc(size, sizeof(int));
			if (!sums[i][j])
				return (-1);
			sums[0][0][0] = triangle[0][0];
			k = 0;
			//left
			while (i - 1 >= 0 && j - 1 >= 0 && sums[i - 1][j - 1][k])
			{
				sums[i][j][k] = triangle[i][j] + sums[i - 1][j - 1][k];
				if (sums[i][j][k] > max)
					max = sums[i][j][k];
				k++;
			}
			l = k;
			k = 0;
			//right
			while (i - 1 >= 0 && j <= i - 1 && sums[i - 1][j][k])
			{
				sums[i][j][l + k] = triangle[i][j] + sums[i - 1][j][k];
				if (sums[i][j][l + k] > max)
					max = sums[i][j][l + k];
				k++;
			}
			j++;
		}
		i++;
	}
	while (--i >= 0)
	{
		j = i;
		while (j >= 0)
			free(sums[i][j--]);
		free(sums[i]);
	}
	free(sums);
	return (max);
}

int	main(void)
{
	int	triangle[SIZE][SIZE] = {
		{75},
		{95, 64},
		{17, 47, 82},
		{18, 35, 87, 10},
		{20, 4, 82, 47, 65},
		{19, 1, 23, 75, 3, 34},
		{88, 2, 77, 73, 7, 63, 67},
		{99, 65, 4, 28, 6, 16, 70, 92},
		{41, 41, 26, 56, 83, 40, 80, 70, 33},
		{41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
		{53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
		{70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
		{91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
		{63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
		{4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}
	};

	printf("%d\n", ft_max_path_sum(triangle));\
}
