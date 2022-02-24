/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:19:06 by aradice           #+#    #+#             */
/*   Updated: 2022/02/05 14:44:24 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_horizontal(int x, char start, char xmiddle, char end)
{
	int	i;

	i = 0;
	while (i < x - 1)
	{
		if (i == 0)
			ft_putchar (start);
		else
			ft_putchar (xmiddle);
		i++;
	}
	if (x == 1)
	{
		ft_putchar (end);
		ft_putchar ('\n');
	}
	else if (i == x - 1)
	{
		ft_putchar (start);
		ft_putchar ('\n');
	}
}

void	ft_vertical(int x, char ymiddle)
{
	int	i;

	i = 0;
	while (i < x - 1)
	{
		if (i == 0)
			ft_putchar (ymiddle);
		else
			ft_putchar (' ');
		i++;
	}
	if (x == 1)
		ft_putchar (ymiddle);
	else if (i == x - 1)
		ft_putchar (ymiddle);
	ft_putchar ('\n');
}

void	rush(int x, int y)
{
	char	start;
	char	end;
	char	xmiddle;
	char	ymiddle;
	int		cursor;

	start = 'A';
	end = 'C';
	xmiddle = 'B';
	ymiddle = 'B';
	cursor = 0;
	if (x > 0 && y > 0)
	{
		while (cursor < y)
		{
			if (cursor == 0)
				ft_horizontal (x, start, xmiddle, end);
			else if (cursor == y - 1)
				ft_horizontal (x, end, xmiddle, start);
			else
				ft_vertical (x, ymiddle);
			cursor++;
		}
	}
}
