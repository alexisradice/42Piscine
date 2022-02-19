/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:54:06 by aradice           #+#    #+#             */
/*   Updated: 2022/02/15 13:07:37 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i] && str2[i] && (str[i] == str2[i]))
		i++;
	return (str[i] - str2[i]);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		y;
	char	*temp;

	i = 1;
	while (i < argc)
	{
		y = i + 1;
		while (y < argc)
		{
			if (ft_strcmp (argv[i], argv[y]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[y];
				argv[y] = temp;
			}
			y++;
		}
		i++;
	}
	i = 0;
	while (++i < argc)
		ft_putstr(argv[i]);
	return (0);
}
