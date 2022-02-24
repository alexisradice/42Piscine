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

int	check(int ok)
{
	if (ok >= 0)
		return (ok);
	else
		return (-ok);
}

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;
	int	size;

	if (min >= max)
		return (0);
	i = 0;
	size = check (max - min);
	tab = malloc(sizeof(int) * (size));
	if (!tab)
		return (NULL);
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	return (tab);
}
