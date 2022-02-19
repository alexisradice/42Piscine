/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:27:58 by aradice           #+#    #+#             */
/*   Updated: 2022/02/10 14:28:00 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	y;

	i = 0;
	if (to_find[i] == 0)
		return (str);
	while (str[i])
	{	
		y = 0;
		while (str[i + y] == to_find[y])
		{	
			if (to_find[y + 1] == '\0')
				return (str + i);
			y++;
		}
		i++;
	}
	return (0);
}
