/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aradice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:58:06 by aradice           #+#    #+#             */
/*   Updated: 2022/02/08 11:44:49 by aradice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		bool_ok;
	char	*temp_str;

	temp_str = str;
	bool_ok = 1;
	while (*str)
	{
		if (check(*str))
		{
			if (*str >= 'A' && *str <= 'Z')
				*str += 32;
			if (*str >= 'a' && *str <= 'z' && bool_ok == 1)
				*str -= 32;
			bool_ok = 0;
		}
		else
			bool_ok = 1;
		str++;
	}
	return (temp_str);
}
