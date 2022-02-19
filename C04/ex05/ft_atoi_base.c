/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:37:09 by aradice           #+#    #+#             */
/*   Updated: 2022/02/15 14:37:11 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi_base(char *str, char *base)
{
	int	val;
	int	compteur;

	val = 0;
	compteur = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			compteur++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		val *= 10;
		val += *str - '0';
		str++;
	}
	if (compteur % 2 != 0)
		return (-val);
	else
		return (val);
}
