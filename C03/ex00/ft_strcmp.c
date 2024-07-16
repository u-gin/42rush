#include <stdio.h>

int ft_strcmp(char *s1, char *s2){
    int i;

    i = 0;
    while (s1[i] != '\0' && (s1[i] == s2[i]))
    {
        i++;
    }

    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int main(void)
{
    char *str0 = "hello my name is Eugene";
    char *str1 = "Hello my name is Eugene";
    char *str2 = "Hello ny name is Eugene";
    char *str3 = "";
    char *str4 = "a boy is not a ";

    printf("1 = %d\n", ft_strcmp(str0, str1));
    printf("2 = %d\n", ft_strcmp(str0, str2));
    printf("3 = %d\n", ft_strcmp(str0, str3));
    printf("4 = %d\n", ft_strcmp(str0, str4));
    return 0;
}
