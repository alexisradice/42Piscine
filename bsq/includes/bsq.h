/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:05:18 by ppajot            #+#    #+#             */
/*   Updated: 2022/02/23 19:35:29 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define BUFFSIZE 1024
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_square
{
	int		x;
	int		y;
	int		size;
	char	empty;
	char	obs;
	char	full;
	int		strlen;
	int		lines;
	int		linelen;
}				t_square;

void	ft_free_array(char **array);
void	ft_free_intarray(int **array, int size);
int		ft_strlen(char *str);
void	ft_square_rec(char **tab, t_square *bsq);
char	**ft_filetostrtab(int fd, int size, t_square *bsq);
char	**ft_split(char *str, char *charset);
int		ft_array_size(char **array);
void	ft_replace(char **grid, t_square bsq);
int		ft_checktab(char **tab, t_square *bsq);
int		**ft_assign_topleft(char **tab, t_square *bsq);
void	ft_square(int **topleft, t_square *bsq);
int		ft_size(char *path);
int		ft_putstr(char *str, int n);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);

#endif
