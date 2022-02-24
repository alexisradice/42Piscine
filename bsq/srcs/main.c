/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:52:27 by ppajot            #+#    #+#             */
/*   Updated: 2022/02/23 19:35:48 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_bsq(int fd, int size)
{
	char		**tab;
	t_square	bsq;
	int			**topleft;

	bsq.size = -1;
	tab = ft_filetostrtab(fd, size, &bsq);
	if (!ft_checktab(tab, &bsq))
	{
		ft_putstr("map error\n", 2);
		ft_free_array(tab);
		return ;
	}
	topleft = ft_assign_topleft(tab, &bsq);
	ft_square(topleft, &bsq);
	ft_replace(tab, bsq);
	ft_free_array(tab);
	ft_free_intarray(topleft, bsq.lines);
}

int	main(int argc, char **argv)
{
	int			fd;
	int			i;
	int			size;

	i = 0;
	if (argc == 1)
		ft_bsq(0, 0);
	else
	{
		while (++i < argc)
		{
			if (i != 1)
				write(1, "\n", 1);
			size = ft_size(argv[i]);
			fd = open(argv[i], 0);
			if (fd == -1)
			{
				ft_putstr("map error\n", 2);
				continue ;
			}
			ft_bsq(fd, size);
			close(fd);
		}
	}
	return (0);
}
