/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:09:08 by aradice           #+#    #+#             */
/*   Updated: 2022/02/03 19:16:22 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	tabnum[2];

	tabnum[0] = 0;
	tabnum[1] = 0;
	while (!(tabnum[0] == 98 && tabnum[1] == 99))
	{
		tabnum[1]++;
		if (tabnum[1] > 99)
		{
			tabnum[0]++;
			tabnum[1] = 0;
		}
		if (tabnum[0] < tabnum[1])
		{
			ft_putchar(tabnum[0] / 10 + '0');
			ft_putchar(tabnum[0] % 10 + '0');
			write(1, " ", 1);
			ft_putchar(tabnum[1] / 10 + '0');
			ft_putchar(tabnum[1] % 10 + '0');
			if (!(tabnum[0] == 98 && tabnum[1] == 99))
			{
				write(1, ", ", 2);
			}
		}
	}
}
