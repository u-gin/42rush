#include <stdio.h>

char *ft_strstr(char *str, char *to_find){

    int i;
    int j;

    i = 0;

    if (to_find[i] == '\0')
    {
        return (str);
    }
    

    while (str[i] != '\0')
    {
        j = 0;
        while (str[i +j] != '\0' && to_find[j] != '\0' && (str[i +j] == to_find[j]))
        {
            
            j++;
        }

        if (to_find[j] == '\0')
        {
            return (&str[i]);
        }
        
        i++;
        
    }
    
    
    return (0);
}

int main(void)
{
    char str0[30] = "Hello my name is Eugene";
    char str1[7] = "";

    char *result = ft_strstr(str0, str1);

    printf("New string is = %s\n", result);
    
    return (0);
}