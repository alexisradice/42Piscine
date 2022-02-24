/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:47:17 by aouichou          #+#    #+#             */
/*   Updated: 2022/02/23 19:27:36 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_word_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_sep(str[i], charset))
		i++;
	return (i);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && ft_is_sep(*str, charset) == 1)
			str++;
		i = ft_word_len(str, charset);
		if (i)
			count++;
		str += i;
	}
	return (count);
}

char	*ft_strcopy(char *src, int i)
{
	int		j;
	char	*dest;

	j = 0;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	while (src[j] && j < i)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		z;
	int		size;
	char	**tab;

	i = 0;
	if (!str[0])
		return (0);
	size = ft_count_words(str, charset);
	tab = (char **)malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (0);
	while (i < size)
	{
		while (ft_is_sep(*str, charset))
			str++;
		z = ft_word_len(str, charset);
		tab[i] = ft_strcopy(str, z);
		str += z;
		i++;
	}
	tab[size] = 0;
	return (tab);
}
