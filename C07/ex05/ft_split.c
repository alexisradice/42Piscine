#include <stdlib.h>
#include <stdio.h>

char **ft_split(char *str, char *charset)
{
	int i;
	int y;
	int z;
	int x;
	int t;
	int u;
	int size;
	char **tab;
	
	i = 0;
	y = 0;
	z = 0;
	x = 0;
	t = 0;
	u = 0;
	size = 0;
	while (str[y])
	{
		if (str[y] == ' ' || str[y] == '\t' || str[y] == '\n')
		{
			size++;
		}
		y++;
	}
	size = size + 1;
	tab = malloc(sizeof(char*) * (size));
	y = 0;
	size = 0;
	while (str[y])
	{
		z = 0;
		t = 0;
		while(str[z] && (!(str[z] == ' ' || str[z] == '\t' || str[z] == '\n')))
		{
			size++;
			printf("OK\n");
			z++;
		}
		if (size > 0)
			tab[x] = malloc(sizeof(char*) * (size + 1));
		while (t < size)
		{
			tab[x][t] = str[u];
			u++;
			t++;
		}
		size = 0;
		x++;
		y++;
	}
	return (tab);
}




char	**ft_split(char *str, char *charset);

int		c_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		c_strctn(char *str1, char *str2, int at)
{
	int	len;
	int	i;

	len = c_strlen(str2);
	i = 0;
	while (i < len)
	{
		str1[at + i] = str2[i];
		i++;
	}
	str1[at + i] = 0;
	return (len + at);
}

char	*c_strautojoin(char **strs, char *sep)
{
	char	*str;
	int		len;
	int		seplen;
	int		i;
	int		j;

	len = 1;
	seplen = c_strlen(sep);
	i = 0;
	while (strs[i] != NULL)
	{
		len += c_strlen(strs[i]);
		if (strs[i + 1] != NULL)
			len += seplen;
		i++;
	}
	str = malloc(len * sizeof(char));
	i = 0;
	j = 0;
	while (strs[j])
	{
		i = c_strctn(str, strs[j++], i);
		if (strs[j])
			i = c_strctn(str, sep, i);
	}
	return (str);
}

int		main(void)
{
	char **tab;

	tab = ft_split("Ceci&est$un##############################################################################################################################################################succes@!", "&$#@");
	printf("%s\n", c_strautojoin(tab, " "));
	tab = ft_split("Success", "CUT");
	printf("%s\n", c_strautojoin(tab, " "));
	tab = ft_split("Success", "");
	printf("%s\n", c_strautojoin(tab, " "));
	tab = ft_split("", "");
	printf("OK\n");
	tab = ft_split("", "CUT");
	printf("OK\n");
	tab = ft_split("       ", "       ");
	printf("OK\n");
	tab = ft_split("         ", "       ");
	printf("OK\n");
}
