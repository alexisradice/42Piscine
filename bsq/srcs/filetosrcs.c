/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filetosrcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:01:14 by ppajot            #+#    #+#             */
/*   Updated: 2022/02/23 19:40:46 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_size(char *path)
{
	int		i;
	int		a;
	char	buff[1024];
	int		sum;

	sum = 0;
	i = open(path, 0);
	if (i == -1)
		return (0);
	a = read(i, buff, 1024);
	if (a == -1)
		return (0);
	while (a > 0)
	{
		sum += a;
		a = read(i, buff, 1024);
		if (a == -1)
			return (0);
	}
	if (close(i) == -1)
		return (0);
	return (sum);
}

char	*ft_allocsupp(char *str, int size)
{
	char	*temp;
	int		n;

	n = ft_strlen(str) + size + 1;
	temp = malloc(sizeof(char) * n);
	temp = ft_strcpy(temp, str);
	free(str);
	str = malloc(sizeof(char) * n);
	str = ft_strcpy(str, temp);
	free(temp);
	return (str);
}

char	*ft_stdintostrtab(void)
{
	char	*str;
	char	buff[1025];
	int		a;

	str = malloc(sizeof(char));
	str[0] = 0;
	buff[1024] = 0;
	a = read(0, buff, 1024);
	while (a)
	{
		buff[a] = 0;
		str = ft_allocsupp(str, a);
		str = ft_strcat(str, buff);
		a = read(0, buff, 1024);
	}
	return (str);
}

char	**ft_filetostrtab(int fd, int size, t_square *bsq)
{
	int		a;
	char	*buff;
	char	**tab;

	if (fd == 0)
	{
		buff = ft_stdintostrtab();
		bsq->strlen = ft_strlen(buff);
		tab = ft_split(buff, "\n");
		free(buff);
		return (tab);
	}
	buff = malloc(sizeof(char) * (size + 1));
	buff[size] = 0;
	a = read(fd, buff, size);
	if (a == -1)
		return (0);
	bsq->strlen = size;
	tab = ft_split(buff, "\n");
	free(buff);
	return (tab);
}
