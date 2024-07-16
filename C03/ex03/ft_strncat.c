#include <stdio.h>

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
    unsigned int i;
    int len;

    i = 0;
    len = 0;

    while (dest[len] != '\0')
    {
        len++;
    }

    while (src[i] != '\0' && i < nb)
    {
        dest[len] = src[i];
        i++;
        len++;
    }

    dest[len] = '\0';

    return (dest);
}

int main(void)
{
    char str0[30] = "Hello ny name is Eugene";
    char str1[] = "a boy is not a ";

    ft_strncat(str0, str1, 3);

    printf("New string is = %s\n", str0);
    return 0;
}
