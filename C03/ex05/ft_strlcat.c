#include <stdio.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size){

    unsigned int i;
    int dest_len;
    int src_len;

    i = 0;
    dest_len = 0;
    src_len = 0;
    while(dest[i] != '\0'){
        dest_len++;
        i++;
    }
    i = 0;
    while (src[i] != '\0')
    {
        src_len++;
        i++;
    }
    i = 0;

    if (size <= dest_len)
    {
        return (size + dest_len);
    }
    

    while (src[i] != '\0' && (dest[dest_len + 1] < size - 1))
    {
        dest[dest_len + i] = src[i];
        i++;
    }

    dest[dest_len + i] = '\0';
    
    return (dest_len + src_len);
}

int main(int argc, char const *argv[])
{
    char str0[57] = "Hello my name is Eugene";
    char str1[24] = " and I live in Ghana";

    int n = ft_strlcat(str0, str1, 25);

    printf("the resulting string is = %s\n", str0);
    printf("the number of copied charaters is = %d\n", n);

    return 0;
}
