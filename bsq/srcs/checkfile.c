/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:10:02 by ppajot            #+#    #+#             */
/*   Updated: 2022/02/23 19:35:26 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_check_char(t_square *bsq)
{
	if (bsq->obs == bsq->empty || bsq->obs == bsq->full
		|| bsq->empty == bsq->full)
		return (0);
	return (1);
}

int	ft_firstline(char **tab, t_square *bsq)
{
	int	i;

	bsq->lines = 0;
	i = 0;
	if (ft_strlen(tab[0]) < 4)
		return (0);
	while (i < ft_strlen(tab[0]) - 3)
	{
		if (tab[0][i] < '0' || tab[0][i] > '9')
			return (0);
		bsq->lines = bsq->lines * 10 + tab[0][i] - '0';
		i++;
	}
	if (tab[0][i] > 126 || tab[0][i] < 32)
		return (0);
	bsq->empty = tab[0][i++];
	if (tab[0][i] > 126 || tab[0][i] < 32)
		return (0);
	bsq->obs = tab[0][i++];
	if (tab[0][i] > 126 || tab[0][i] < 32)
		return (0);
	bsq->full = tab[0][i];
	return (ft_check_char(bsq));
}

int	ft_checktab(char **tab, t_square *bsq)
{
	int		i;
	int		j;

	i = 1;
	if (!tab || !tab[0] || !tab[1])
		return (0);
	bsq->linelen = ft_strlen(tab[1]);
	if (!ft_firstline(tab, bsq))
		return (0);
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] != bsq->empty && tab[i][j] != bsq->obs)
				return (0);
			j++;
		}
		if (j != bsq->linelen)
			return (0);
		i++;
	}
	return (bsq->strlen == (ft_strlen(tab[0]) + 1
			+ (bsq->linelen + 1) * bsq->lines));
}
