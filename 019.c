/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   019.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 08:28:33 by arabenst          #+#    #+#             */
/*   Updated: 2023/03/02 10:57:08 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_date
{
	int	weekday;
	int	day;
	int	month;
	int	year;
}	t_date;

t_date	ft_add_day(t_date date)
{
	int	last_day;

	if (date.month == 2)
		last_day = 28 + (date.year % 4 == 0 && (date.year % 100 != 0
			|| date.year % 400 == 0));
	else if (date.month == 4 || date.month == 6 || date.month == 9
		|| date.month == 11)
		last_day = 30;
	else
		last_day = 31;
	if (++date.day > last_day)
	{
		date.day = 1;
		if (++date.month > 12)
		{
			date.month = 1;
			date.year++;
		}
	}
	if (date.weekday >= 0)
		if (++date.weekday > 6)
			date.weekday = 0;
	return (date);
}

int	ft_days_between_dates(t_date a, t_date b)
{
	t_date	start;
	t_date	end;
	int		count;

	start = a;
	end = b;
	if (b.year < a.year)
	{
		start = ft_add_day(b);
		end = a;
	}
	count = 0;
	while (start.year != end.year || start.month != end.month
		|| start.day != end.day)
	{
		start = ft_add_day(start);
		count++;
	}
	return (count);
}

t_date ft_set_date(t_date anker, int weekday, int day, int month, int year)
{
	t_date date;

	date.weekday = weekday;
	date.day = day;
	date.month = month;
	date.year = year;
	if (weekday == -1)
		date.weekday = ft_days_between_dates(anker, date) % 7;
	return (date);
}

int	ft_count_sundays_on_first_of_month_in_century(int century, int weekday)
{
	t_date	anker;
	t_date	start;
	t_date	end;
	int		count;

	anker = ft_set_date(anker, 0, 1, 1, 1900);
	start = ft_set_date(anker, -1, 1, 1, (century - 1) * 100 + 1);
	// printf("START: %02d/%02d/%4d is weekday %d\n", start.month, start.day, start.year, start.weekday);
	end = ft_set_date(anker, -1, 31, 12, century * 100);
	// printf("END: %02d/%02d/%4d is weekday %d\n", end.month, end.day, end.year, end.weekday);
	count = 0;
	while (start.year != end.year || start.month != end.month
		|| start.day != end.day)
	{
		if (start.weekday == weekday && start.day == 1)
			count++;
		start = ft_add_day(start);
	}
	return (count);
}

int	main(void)
{
	printf("%d\n", ft_count_sundays_on_first_of_month_in_century(19, 6));
}
