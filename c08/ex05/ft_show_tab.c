/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 23:32:45 by aradice           #+#    #+#             */
/*   Updated: 2022/02/21 20:38:41 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
}

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

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (par[i].str)
	{
		write (1, par[i].str, par[i].size);
		write (1, "\n", 1);
		ft_putnbr (par[i].size);
		write (1, "\n", 1);
		write (1, par[i].copy, par[i].size);
		write (1, "\n", 1);
		i++;
	}
}
