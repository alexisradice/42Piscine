/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:31:52 by aradice           #+#    #+#             */
/*   Updated: 2022/02/15 13:31:54 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int check(int ok)
{
	if (ok >= 0)
		return (ok);
	else
		return (-ok);
}

int *ft_range(int min, int max)
{
	int *tab;
	int i;
	int size;
	
	if (min >= max)
	{
		tab = malloc(1);
		tab = NULL;
		return (tab);
	}
		
	i = 0;
	size = check (max - min);
	tab = malloc(sizeof(int) * (size + 1));
	if (!tab)
		return (NULL);
	while(min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	tab[i] = max;
	return (tab);
}

void test(int min, int max)
{
	int *range = ft_range(min, max);
	
	printf("%i - %i | ", min, max);

	if (range)
	{
		for (int i = 0; i <  max - min; i++)
		{
			printf("%i ", range[i]);
		}

		free(range);

		printf("\n");
	}
	else
		printf("ERROR\n");
}

int main()
{
	test(0, 10);
	test(10, 10);
	test(15, 16);
	test(0, 1);
	test(-10, 10);
	test(-105, -104);
	test(50, 55);
	test(10, 8);
	test(2147483647 - 5, 2147483647);
	test(-2147483648, -2147483648 + 5);
}
