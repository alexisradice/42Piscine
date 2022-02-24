/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topleft                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:37:32 by ppajot            #+#    #+#             */
/*   Updated: 2022/02/23 19:32:04 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_isobs(int x, int y, char **tab, t_square *bsq)
{
	if (tab[x + 1][y] == bsq->empty)
		return (0);
	return (1);
}

int	**ft_filltopleft(int **topleft, char **tab, t_square *bsq)
{
	int	i;
	int	j;

	i = 0;
	topleft[0][0] = ft_isobs(0, 0, tab, bsq);
	while (++i < bsq->linelen)
		topleft[0][i] = topleft[0][i - 1] + ft_isobs(0, i, tab, bsq);
	i = 0;
	while (++i < bsq->lines)
		topleft[i][0] = topleft[i - 1][0] + ft_isobs(i, 0, tab, bsq);
	i = 0;
	while (++i < bsq->lines)
	{
		j = 0;
		while (++j < bsq->linelen)
			topleft[i][j] = topleft[i][j - 1] + topleft[i - 1][j]
				- topleft[i - 1][j - 1] + ft_isobs(i, j, tab, bsq);
	}
	return (topleft);
}

int	**ft_assign_topleft(char **tab, t_square *bsq)
{
	int	i;
	int	**topleft;

	topleft = malloc(sizeof(int *) * bsq->lines);
	if (topleft == 0)
		return (0);
	i = -1;
	while (++i < bsq->lines)
	{
		topleft[i] = malloc(sizeof(int) * bsq->linelen);
		if (topleft[i] == 0)
			return (0);
	}
	return (ft_filltopleft(topleft, tab, bsq));
}
