#include <unistd.h>
#include <stdlib.h>

typedef struct s_dict
{
    unsigned long long number;
    char *word;
    struct s_dict *next;
} t_dict;

t_dict *load_dict(char *filename);
void free_dict(t_dict *dict);
void convert_number(t_dict *dict, unsigned long long n);
int is_valid_number(char *str);
unsigned long long ft_atoi(char *str);

int main(int argc, char **argv)
{
    t_dict *dict;
    char *number_str;

    if (argc < 2 || argc > 3)
    {
        write(1, "Error\n", 6);
        return 1;
    }

    if (argc == 2)
    {
        dict = load_dict("numbers.dict");
        number_str = argv[1];
    }
    else
    {
        dict = load_dict(argv[1]);
        number_str = argv[2];
    }

    if (!dict)
    {
        write(1, "Dict Error\n", 11);
        return 1;
    }

    if (!is_valid_number(number_str))
    {
        write(1, "Error\n", 6);
        free_dict(dict);
        return 1;
    }

    unsigned long long num = ft_atoi(number_str);
    convert_number(dict, num);

    free_dict(dict);
    return 0;
}