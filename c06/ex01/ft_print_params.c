/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:54:06 by aradice           #+#    #+#             */
/*   Updated: 2022/02/11 12:09:35 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	y;

	i = 1;
	while (i < argc)
	{
		y = 0;
		while (argv[i][y] != '\0')
		{
			write (1, &argv[i][y], 1);
			y++;
		}
		write (1, "\n", 1);
		i++;
	}
	return (0);
}
