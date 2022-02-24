/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:27:12 by aradice           #+#    #+#             */
/*   Updated: 2022/02/22 23:27:13 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_charset(char *charset, char charr)
{
	int	i;

	i = 0;
	if (charr == '\0')
		return (1);
	while (charset[i])
	{
		if (charset[i] == charr)
			return (1);
		i++;
	}
	return (0);
}

void	ft_strcpy(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (ft_charset(charset, src[i]) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	process(char *str, char *charset, char **tab)
{
	int	i;
	int	y;
	int	w;

	i = 0;
	w = 0;
	while (str[i])
	{
		if (ft_charset(charset, str[i]) == 0)
		{
			y = 0;
			while (ft_charset(charset, str[i + y]) == 0)
				y++;
			tab[w] = malloc((y + 1) * sizeof(char));
			ft_strcpy(tab[w], (str + i), charset);
			w++;
			i = i + y;
		}
		else if (ft_charset(charset, str[i]) == 1)
			i++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		w;
	int		i;

	i = 0;
	w = 0;
	while (str[i])
	{
		if (ft_charset(charset, str[i + 1]) == 1)
			if (ft_charset(charset, str[i]) == 0)
				w++;
		i++;
	}
	tab = malloc (sizeof(char *) * (w + 1));
	tab[w] = 0;
	process (str, charset, tab);
	return (tab);
}
