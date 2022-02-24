/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:47:06 by aradice           #+#    #+#             */
/*   Updated: 2022/02/12 16:47:08 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_checkarg(char *str)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (str[length])
		length++;
	if (length == 31)
	{
		while (str[i])
		{
			if (i % 2 == 0)
			{
				if (!((str[i] >= 49) && (str[i] <= 52)))
					return (0);
			}
			else
			{
				if (!(str[i] == ' '))
					return (0);
			}
			i++;
		}
	}
	else
		return (0);
	return (1);
}

char	veriftwo(int compteur, int compteur2, int compteur3, int compteur4, char **tabstr,
		char *str, int i, int y, int val, int val2, int val3, int val4)
{
	i = 0;
	while (i < 4)
	{
		y = 0;
		val = '0';
		compteur = 0;
		compteur2 = 0;
		val2 = '0';
		compteur3 = 0;
		val3 = '0';
		compteur4 = 0;
		val4 = '0';
		while (y < 4)
		{
			if (val < tabstr[y][i])
			{
				val = tabstr[y][i];
				compteur++;
			}
			if (y == 3)
			{
				if (compteur + '0' != str[i])
					return (0);
			}	
			if (val3 < tabstr[3 - y][i])
			{
				val3 = tabstr[3 - y][i];
				compteur3++;
			}
			if (y == 3)
			{
				if (compteur3 + '0' != str[i + 4] || (tabstr[0][i]
						+ tabstr[1][i] + tabstr[2][i] + tabstr[3][i]) != 202)
					return (0);
			}
			if (val4 < tabstr[i][3 - y])
			{
				val4 = tabstr[i][3 - y];
				compteur4++;
			}
			if (y == 3)
			{
				if (compteur4 + '0' != str[i + 12] || (tabstr[y][0]
						+ tabstr[y][1] + tabstr[y][2] + tabstr[y][3]) != 202)
					return (0);
			}
			if (val2 < tabstr[i][y])
			{
				val2 = tabstr[i][y];
				compteur2++;
			}
			if (y == 3)
			{
				if (compteur2 + '0' != str[i + 8] || (tabstr[y][0]
						+ tabstr[y][1] + tabstr[y][2] + tabstr[y][3]) != 202)
					return (0);
			}
			y++;
		}
		i++;
	}
	return (1);
}

char	verif(char *str, char **tabstr)
{
	int		compteur;
	char	val;
	int		compteur2;
	char	val2;
	int		compteur3;
	char	val3;
	int		compteur4;
	char	val4;
	int		i;
	int		y;

	compteur = 0;
	val = '0';
	compteur2 = 0;
	val2 = '0';
	compteur3 = 0;
	val3 = '0';
	i = 0;
	y = 0;
	return (veriftwo(compteur, compteur2, compteur3, compteur4, tabstr, str, i, y, val,
				val2, val3, val4));
}

char	*recup_arg(char *str)
{
	int		compteur;
	char	*str2;
	int		i;
	int		y;

	str2 = malloc(sizeof(char) * 8);
	compteur = 0;
	i = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			compteur++;
		if (str[i] != ' ')
		{
			str2[y] = str[i];
			y++;
		}
		i++;
	}
	str[y] = '\0';
	return (str2);
}

void	ft_display(char **array)
{
	printf("%s\n", array[0]);
	printf("%s\n", array[1]);
	printf("%s\n", array[2]);
	printf("%s\n", array[3]);
}

void	ft_change(char **array, int i, int y, int x, int z)
{
	char	*tab[24] = {"1234", "1243", "1324", "1342",
		"1423", "1432", "2341", "2314", "2413", "2431", "2134",
		"2143", "3412", "3124", "3142", "3214", "3241", "3421",
		"4123", "4132", "4213", "4231", "4312", "4321"};
	array[0] = tab[i];
	array[1] = tab[y];
	array[2] = tab[x];
	array[3] = tab[z];
}

char	ft_process(char **array, int i, int y, int x, int z, char *str)
{
	while (i < 24)
	{
		y = 0;
		while (y < 24)
		{
			x = 0;
			while (x < 24)
			{
				z = 0;
				while (z < 24)
				{
					ft_change(array, i, y, x, z);
					if (verif(str, array) == 1)
					{
						ft_display(array);
						return (1);
					}
					z++;
				}
				x++;
			}
			y++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*str;
	int		i;
	int		y;
	int		x;
	int		z;
	int		t;
	char	**array;

	array = malloc(4 * sizeof(char *));
	if (!array)
		return (0);
	i = 0;
	y = 0;
	t = 0;
	z = 0;
	x = 0;
	if (argc == 2)
	{
		if (ft_checkarg(argv[1]) == 1)
		{
			str = recup_arg(argv[1]);
			while (t < 4)
			{
				array[t] = malloc(4 * sizeof(char));
				if (!array[t])
					return (0);
				t++;
			}
			if (!(ft_process(array, i, y, x, z, str) == 1))
				printf("Error\n");
		}
		/*
		t = 0;
		while (t < 4)
		{
			free(array[t]);
			t++;
		}
		free(array);
		*/
	}
	return (0);
}
