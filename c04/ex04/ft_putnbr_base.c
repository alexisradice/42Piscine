/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:44:36 by aradice           #+#    #+#             */
/*   Updated: 2022/02/14 15:58:54 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_process(int *tab, int i, long long nb, char *base)
{
	int	len;

	len = 0;
	while (base[len])
		len++;
	if (nb != 0)
	{
		while (nb != 0)
		{
			tab[i] = base[nb % len];
			i--;
			nb = nb / len;
		}
		while (i < 99)
		{
			write (1, &tab[i + 1], 1);
			i++;
		}
	}
	else
		write (1, "0", 1);
}

void	ft_putnbr_base(int nb, char *base)
{
	int			tab[100];
	int			i;
	long long	nbr;

	nbr = nb;
	i = 99;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		write(1, "-", 1);
	}
	ft_process(tab, i, nbr, base);
}
