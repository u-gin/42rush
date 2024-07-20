#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_atoi(char *argv);
void handle_arg_errors(int num_to_convert, char *filename);

int main(int argc, char **argv)
{

    int num_to_convert;
    char *filename;
    FILE *file;

    if (argc > 3)
    {
        write(1, "Error\n", 6);
        return 1;
    }
    else if (argc == 3)
    {
        num_to_convert = ft_atoi(argv[2]);
        filename = argv[1];
    }
    else if (argc == 2)
    {
        num_to_convert = ft_atoi(argv[1]);
        filename = "numbers.dict";
    }
    else
    {
        write(1, "Error\n", 6);
        return 1;
    }

    handle_arg_errors(num_to_convert, filename);

    
    return 0;
}

void handle_arg_errors(int num_to_convert, char *filename)
{
    FILE *dict_file;
    dict_file = fopen(filename, "r");
    if (num_to_convert < 0)
    {
        write(1, "Error\n", 6);
        return;
    }
    if (!dict_file)
    {
        write(1, "Dict Error\n", 11);
        return;
    }
    
}

//this is the atoi function.
int ft_atoi(char *argv)
{
    int sign;
    int result;
    int i;

    sign = 1;
    result = 0;
    i = 0;

    // handling empty spaces
    while (argv[i] == ' ' || argv[i] == '\t' || argv[i] == '\n')
    {
        i++;
    }

    // handlding sigs
    while (argv[i] == '-' || argv[i] == '+')
    {
        if (argv[i] == '-')
        {
            sign = -sign;
            i++;
        }
        else
        {
            i++;
        }
    }

    // converting to int
    while (argv[i] >= '0' && argv[i] <= '9')
    {
        result = result * 10 + (argv[i] - '0');
        i++;
    }

    return (result * sign);
}