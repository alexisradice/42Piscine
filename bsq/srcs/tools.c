/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:10:26 by ppajot            #+#    #+#             */
/*   Updated: 2022/02/23 20:12:40 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str, int n)
{
	int	l;

	l = ft_strlen(str);
	write(n, str, l);
	return (0);
}

void	ft_free_intarray(int **array, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(array[i]);
	free(array);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i] != 0)
	{
		free(array[i]);
		i++;
	}
	free(array[i]);
	free(array);
}

int	ft_array_size(char **array)
{
	int	i;

	i = 0;
	while (array[i] != 0)
		i++;
	return (i);
}
