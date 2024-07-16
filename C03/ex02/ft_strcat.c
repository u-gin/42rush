#include <stdio.h>

char *ft_strcat(char *dest, char *src){
    int i;
    int len;

    i = 0;
    len = 0;


    while (dest[len] != '\0')
    {
       len++;
    }
    
    while (src[i] != '\0')
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

    ft_strcat(str0, str1);

    printf("New string is = %s\n", str0);
    return 0;
}
