/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   015.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:12:05 by arabenst          #+#    #+#             */
/*   Updated: 2023/02/22 10:28:27 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long long	ft_how_many_routes(int grid, int x, int y, long long count)
{
	if (x < grid)
		count = ft_how_many_routes(grid, x + 1, y, count);
	if (y < grid)
		count = ft_how_many_routes(grid, x, y + 1, count);
	if (x == grid && y == grid)
		return (count + 1);
	return (count);
}

int	main(void)
{
	printf("%lld\n", ft_how_many_routes(20, 0, 0, 0));
}
