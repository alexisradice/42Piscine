/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:49:43 by jileroux          #+#    #+#             */
/*   Updated: 2022/02/06 23:19:33 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);

int	ft_strint(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		i *= 10;
		i += *str - '0';
		str++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (argc == 3)
	{
		x = ft_strint(argv[1]);
		y = ft_strint(argv[2]);
	}
	if (x > 0 && y > 0)
		rush (x, y);
	return (0);
}
