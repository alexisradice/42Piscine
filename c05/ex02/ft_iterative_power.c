/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:14:20 by aradice           #+#    #+#             */
/*   Updated: 2022/02/15 12:14:21 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	temp;

	i = 1;
	temp = nb;
	if (power > 0)
	{
		while (i < power)
		{
			nb = nb * temp;
			i++;
		}
		return (nb);
	}
	else if (power < 0)
		return (0);
	else
		return (1);
}
