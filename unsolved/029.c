/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   029.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:14:19 by arabenst          #+#    #+#             */
/*   Updated: 2023/03/23 10:34:10 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft/libft.h"

// int	ft_distinct_powers(int max)
// {
// 	char	*powers;
// 	int		a;
// 	int		b;

// 	powers = ft_calloc(ft_pow(max, max), sizeof(char));
// 	if (!powers)
// 		return (-1);
// 	a = 1;
// 	while (++a <= max)
// 	{
// 		b = 1;
// 		while (++b <= max)
// 			powers[ft_pow(a, b)] = 1;
// 	}
// 	a = 0;
// 	b = 0;
// 	while (a <= ft_pow(max, max))
// 		if (powers[a++] == 1)
// 			b++;
// 	return (b);
// }

// int	main(void)
// {
// 	ft_printf("%d\n", ft_distinct_powers(8));
// }

#include<stdio.h>
#include<math.h>

int a,b;

struct pair
{
      int x,y;
};

struct pair p[9801];
int isEqual(int,int);
void setToBasic(int);
int main()
{
      int i,j,counter=0,answer;
      for(i=2;i<=100;i++)
            for(j=2;j<=100;j++)
            {
                  p[counter].x=i;
                  p[counter].y=j;
                  counter++;
            }

      for(i=0;i<9801;i++)
            setToBasic(i);

      answer=9801;

      for(i=9800;i>=0;i--)
            for(j=i-1;j>=0;j--)
                  if(p[i].x && p[i].y && isEqual(i,j))
                        answer--;

      printf("answer = %d\n",answer);
      return 0;
}

int isEqual(int i,int j)
{
      if(p[i].x==p[j].x && p[i].y==p[j].y)
      {
            p[j].x=p[j].y=0;
            return 1;
      }
      return 0;
}

void setToBasic(int counter)
{
      int i,j;
      for(i=2;i<p[counter].x;i++)
            for(j=2;pow(i,j)<=p[counter].x;j++)
                  if(pow(i,j)==p[counter].x)
                  {
                        p[counter].x=i;
                        p[counter].y*=j;
                  }
}
