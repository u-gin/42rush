#include <stdio.h>

int ft_strncmp(char *s1, char *s2, unsigned int n){

    unsigned int i;

    i = 0;

    while ((s1[i] != '\0' || s2[i] != '\0') && i < n)   
    {
        if ((s1[i] != s2[i]))
        {
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        }
        
        i++;
    }

    return (0);
    
 }

int main(void)
{
    char *str0 = "hello my name is Eugene";
    char *str1 = "Hello my name is Eugene";
    char *str2 = "Hello ny name is Eugene";
    char *str3 = "";
    char *str4 = "a boy is not a ";

    printf("1 = %d\n", ft_strncmp(str0, str1, 4));
    printf("1 = %d\n", ft_strncmp(str0, str1, 6));
    printf("2 = %d\n", ft_strncmp(str0, str2, 7));
    printf("3 = %d\n", ft_strncmp(str0, str3, 1));
    printf("4 = %d\n", ft_strncmp(str0, str4, 3));
    return 0;
}