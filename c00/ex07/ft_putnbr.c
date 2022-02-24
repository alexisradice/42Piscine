/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:32:18 by aradice           #+#    #+#             */
/*   Updated: 2022/02/03 19:00:37 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_process(int *tab, int i, int nb)
{
	if (nb != 0)
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
		write (1, "0", 1);
}

void	ft_putnbr(int nb)
{
	int	tab[10];
	int	i;

	i = 9;
	if (nb == -2147483648)
		write (1, "-2147483648", 11);
	if (nb < 0)
	{
		nb = nb * -1;
		write(1, "-", 1);
	}
	ft_process(tab, i, nb);
}
