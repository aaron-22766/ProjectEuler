/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   022.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 08:27:32 by arabenst          #+#    #+#             */
/*   Updated: 2023/03/13 16:01:11 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"

int	ft_get_worth(char *name)
{
	int	i;
	int	worth;

	i = 1;
	worth = 0;
	while (name[i] != '\"')
	{
		if (ft_isupper(name[i]))
			worth += name[i] - 'A' + 1;
		else
			worth += name[i] - 'a' + 1;
		i++;
	}
	return (worth);
}

char	**ft_get_list(char *file_name, int size)
{
	char	**list;
	int		fd;
	char	*file;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	file = calloc(size + 1, sizeof(char));
	if (!file)
		return (NULL);
	if (read(fd, file, size) == -1)
		return (close(fd), NULL);
	close(fd);
	list = ft_split(file, ',');
	free(file);
	return (list);
}

void	ft_bubble_sort(char **list)
{
	int		i;
	int		j;
	int		size;
	char	*temp;

	i = 0;
	while (list[i + !!i])
	{
		j = i + 1;
		while (list[j])
		{
			size = ft_strlen(list[i]);
			if (size < ft_strlen(list[j]))
				size = ft_strlen(list[j]);
			if (ft_strncmp(list[i], list[j], size) > 0)
			{
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
			j++;
		}
		i++;
	}
}

long long int	ft_get_total_of_name_scores(char *file_name, int size)
{
	char			**list;
	long long int	total;
	int				i;

	list = ft_get_list(file_name, size);
	if (!list)
		return (-1);
	ft_bubble_sort(list);
	total = 0;
	i = 0;
	while (list[i])
	{
		total += (i + 1) * ft_get_worth(list[i]);
		i++;
	}
	return (total);
}

int	main(void)
{
	printf("%lld\n", ft_get_total_of_name_scores("022_names.txt", 46447));
}
