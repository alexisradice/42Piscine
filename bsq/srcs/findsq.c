/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:59:10 by ppajot            #+#    #+#             */
/*   Updated: 2022/02/23 19:35:40 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
/*
void	ft_assign(int x, int y, int newsize, t_square *bsq)
{
	if (newsize > bsq->size)
	{
		bsq->size = newsize;
		bsq->x = x;
		bsq->y = y;
	}
}*/

int	ft_topleftlimits(int x, int y, int **topleft)
{
	if (x < 0 || y < 0)
		return (0);
	else
		return (topleft[x][y]);
}

void	ft_sqisvalid(int x, int y, int **topleft, t_square *bsq)
{
	int	n;

	if (bsq->linelen - y < bsq->lines - x)
		n = bsq->linelen - y;
	else
		n = bsq->lines - x;
	while (bsq->size + 1 < n)
	{
		if (ft_topleftlimits(x + bsq->size + 1, y + bsq->size + 1, topleft)
			- ft_topleftlimits(x - 1, y + bsq->size + 1, topleft)
			- ft_topleftlimits(x + bsq->size + 1, y - 1, topleft)
			+ ft_topleftlimits(x - 1, y - 1, topleft))
			return ;
		bsq->size++;
		bsq->x = x + 1;
		bsq->y = y;
	}
}

void	ft_square(int **topleft, t_square *bsq)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (x == bsq->lines)
		return ;
	while (x < bsq->lines - bsq->size)
	{
		ft_sqisvalid(x, y, topleft, bsq);
		if (y + 1 >= bsq->linelen - bsq->size)
		{
			x++;
			y = 0;
		}
		else
			y++;
	}
	bsq->size++;
}
