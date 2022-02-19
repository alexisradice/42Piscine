#include <stdio.h>
#include <stdlib.h>

char *ft_strjoin(int size, char **strs, char *sep)
{
	char *str;
	int i;
	int y;
	int cmp;
	int z;
	
	i = 0;
	y = 0;
	cmp = 0;
	z = 0;
	while (sep[cmp])
		cmp++;
	cmp = cmp * (size - 1);
	while(i < size)
	{
		y = 0;
		while(strs[i][y])
		{
			cmp++;
			y++;		
		}
		i++;
	}
	str = malloc(sizeof(char) * (cmp + 1));
	i = 0;
	y = 0;
	cmp = 0;
	while(i < size)
	{
		y = 0;
		cmp = 0;
		while(strs[i][y])
		{
			str[z] = strs[i][y];
			y++;
			z++;
		}
		if (i != (size - 1))
		{
			while(sep[cmp])
			{
				str[z] = sep[cmp];
				cmp++;
				z++;
			}
		}
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	printf("./ex03/output___said___this___is___a___success :\n");
	printf("%s\n",  ft_strjoin(argc, argv, "**"));
}
