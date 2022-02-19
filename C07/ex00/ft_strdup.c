/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:29:10 by aradice           #+#    #+#             */
/*   Updated: 2022/02/15 13:29:13 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

char *ft_strdup(char *src)
{
	char *str;
	int i;
	int y;
	
	i=0;
	y=0;

	while (str[i])
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i=0;
	while(src[y])
	{
		str[i] = src[y];
		y++;
		i++;
	}
	return (str);	
}

int main()
{
	char test[] = "qwertyup";
	printf("%s", ft_strdup(test));
	return (0);
}
