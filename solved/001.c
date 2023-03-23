/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Multiples of 3 or 5.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:38:09 by arabenst          #+#    #+#             */
/*   Updated: 2023/02/15 13:42:51 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	result;
	int	max;
	int	i;

	max = 1000;
	result = 0;
	i = 0;
	while (i < max)
	{
		if (i % 3 == 0 || i % 5 == 0)
			result += i;
		i++;
	}
	printf("%d\n", result);
}
