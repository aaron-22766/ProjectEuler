/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   018.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:37:38 by arabenst          #+#    #+#             */
/*   Updated: 2023/02/24 15:49:32 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

int ft_get_worth(int i, int j)
{
	if (i == 0 && j == 0)
		return 0;
	else if (i == j || j == 0)
		return 1;
	return (ft_get_worth(i - 1, j - 1) + ft_get_worth(i - 1, j));
}

int	ft_max_path_sum(int triangle[SIZE][SIZE])
{
	int	***values;
	int	i;
	int	j;
	int	k;
	int	sum;
	int	value;
	int	size;

	sum = 0;
	i = 0;
	values = calloc(SIZE + 1, sizeof(int **));
	if (!values)
		return (-1);
	while (i < SIZE)
	{
		values[i] = calloc(i + 2, sizeof(int *));
		if (!values[i])
			return (-1);
		j = 0;
		while (j < i + 1)
		{
			printf("t[%d][%d] = %d\n", i, j, triangle[i][j]);
			size = ft_get_worth(i, j) + (i + j == 0) + 1;
			values[i][j] = calloc(size, sizeof(int));
			if (!values[i][j])
				return (-1);
			if (i == 0)
			{
				values[0][0][0] = triangle[i][j];
				break ;
			}
			k = 0;
			//left
			while (values[i - 1][j - 1][k] && i - 1 >= 0 && j - 1 >= 0)
			{
				values[i][j][k] = triangle[i][j] + values[i - 1][j - 1][k];
				k++;
			}
			k = 0;
			//right
			while (values[i - 1][j][k] && i - 1 >= 0)
			{
				values[i][j][k] = triangle[i][j] + values[i - 1][j][k];
				k++;
			}
			j++;
		}
		i++;
	}
	return (sum);
}

int	main(void)
{
	int	triangle[SIZE][SIZE] = {
		{3},
		{7, 4},
		{2, 4, 6},
		{8, 5, 9, 3}
	};

	printf("%d\n", ft_max_path_sum(triangle));
}

/**
 * [0] 3 - 7 - 2 - 8 = 20
 * [1] 3 - 7 - 2 - 5 = 17
 * [2] 3 - 7 - 4 - 5 = 19
 * [3] 3 - 7 - 4 - 9 = 23
 * [4] 3 - 4 - 4 - 5 = 16
 * [5] 3 - 4 - 4 - 9 = 20
 * [6] 3 - 4 - 6 - 9 = 22
 * [7] 3 - 4 - 6 - 3 = 16
 */

// 75
// 95 64
// 17 47 82
// 18 35 87 10
// 20 04 82 47 65
// 19 01 23 75 03 34
// 88 02 77 73 07 63 67
// 99 65 04 28 06 16 70 92
// 41 41 26 56 83 40 80 70 33
// 41 48 72 33 47 32 37 16 94 29
// 53 71 44 65 25 43 91 52 97 51 14
// 70 11 33 28 77 73 17 78 39 68 17 57
// 91 71 52 38 17 14 91 43 58 50 27 29 48
// 63 66 04 68 89 53 67 30 73 16 69 87 40 31
// 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
