#include <stdlib.h>
#include <stdio.h>

void write_tab(char *dest, char *from)
{
    int i;

    i=0;
    while (!(from[i] == ' ' || from[i] == '\n' || from[i] == '\t'))
    {
        dest[i] = from[i];
        i++;
    }
    dest[i] = '\0';
}

void write_split(char *str, char **tab)
{
    int i;
    int y;
    int word;

    i=0;
    y=0;
    word = 0;
    while(str[i])
    {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
            i++;
        else
        {
            y = 0;
            while (!(str[i+y] == ' ' || str[i+y] == '\n' || str[i+y] == '\t'))
                y++;
            tab[word] = (char*)malloc(sizeof(char) * (y + 1));
            write_tab(tab[word], (str + i));
            i = y + i;
            word++;
        }
    }
}

char **ft_split(char *str)
{
    char **tab;
    int i;
    int len;

    i = 0;
    len = 0;
    while(str[len])
    {
        len++;
    }
    tab = (char**)malloc(sizeof(char*) * (len + 1));
    write_split(str, tab);
    return (tab);
}

int		main(void)
{
	char *tab;
	tab = "Ce\nfehfbj fzkfb\tdfjkzb";
    printf("%s\n",  ft_split(tab)[0]);
    printf("%s\n",  ft_split(tab)[1]);
    printf("%s\n",  ft_split(tab)[2]);
    printf("%s\n",  ft_split(tab)[3]);
    return (0);
}