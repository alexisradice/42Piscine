#include <stdio.h>
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

void	ft_strcat(char *dest, char *src)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	printf("%s",src);
	while (dest[i])
	{
		i++;
	}
	while (src[y])
	{
		dest[i+y] = src[y];
		y++;
	}
}

char *ft_strjoin(int size, char **strs, char *sep)
{
char *test;
int i;
int y;

i=0;
y=0;
while (strs[i])
{
	y = y + ft_strlen(strs[i]);
	i++;
}
test = malloc(y + (ft_strlen(sep) * i) *  (sizeof (char)));
if (!test)
	return NULL;
i=0;
while (strs[i+1])
{
ft_strcat(test, strs[i]);
ft_strcat(test, sep);
i++;
}
return (test);
}

#include <stdio.h>

char *ft_strjoin(int size, char **strs, char *sep);

int	main(int argc, char **argv)
{
	printf("./ex03/output___said___this___is___a___success :\n");
	printf("%s\n",  ft_strjoin(argc, argv, "___"));
}