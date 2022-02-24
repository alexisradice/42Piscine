/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:47:38 by ppajot            #+#    #+#             */
/*   Updated: 2022/02/23 19:42:23 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_display(char **grid, t_square bsq)
{
	int	x;

	x = 0;
	while (x < bsq.lines)
	{
		ft_putstr(grid[x + 1], 1);
		write(1, "\n", 1);
		x++;
	}
}

void	ft_replace(char **grid, t_square bsq)
{
	int	i;
	int	y;

	i = bsq.x;
	while (i < (bsq.x + bsq.size))
	{
		y = bsq.y;
		while (y < (bsq.y + bsq.size))
		{
			grid[i][y] = bsq.full;
			y++;
		}	
		i++;
	}
	ft_display(grid, bsq);
}
