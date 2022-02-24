/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:53:12 by aradice           #+#    #+#             */
/*   Updated: 2022/02/21 20:53:14 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_len(int size, char **str, int sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(str[i]);
		if (str[i + 1])
			len += sep;
		else
			len += 1;
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*test;
	int		i;

	i = 0;
	if (size < 0)
		return (NULL);
	test = malloc(sizeof(char) * ft_len(size, strs, ft_strlen(sep)));
	test[0] = 0;
	if (!test)
		return (NULL);
	while (i < size)
	{
		ft_strcat(test, strs[i]);
		if (i < size -1)
			ft_strcat(test, sep);
		i++;
	}
	return (test);
}
