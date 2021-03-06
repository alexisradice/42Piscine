/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:13:38 by aradice           #+#    #+#             */
/*   Updated: 2022/02/15 12:13:39 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	val;

	val = 1;
	i = 1;
	if (nb < 0)
		return (0);
	while (i <= nb)
	{
		val *= i;
		i++;
	}
	return (val);
}
