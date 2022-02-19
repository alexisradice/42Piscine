/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:32:18 by aradice           #+#    #+#             */
/*   Updated: 2022/02/14 15:43:43 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_process(int *tab, int i, int nb, int ok)
{
	if (nb != 0 && ok == 1)
	{
		while (nb != 0)
		{
			tab[i] = nb % 10 + '0';
			i--;
			nb = nb / 10;
		}
		while (i < 9)
		{
			write (1, &tab[i + 1], 1);
			i++;
		}
	}
	else
		if (ok == 1)
			write (1, "0", 1);
}

void	ft_putnbr(int nb)
{
	int	tab[10];
	int	i;
	int	ok;

	i = 9;
	ok = 1;
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		ok = 0;
	}
	if (nb < 0 && ok == 1)
	{
		nb = nb * -1;
		write(1, "-", 1);
	}
	ft_process(tab, i, nb, ok);
}
