#include <stdlib.h>
int ft_strlen(const char *s);
void ft_putstr(const char *s);
int ft_is_number(char *s);

void number_to_words(int n);

int main(int argc, char **argv)
{
    int num;

    if (argc != 2)
    {
        ft_putstr("Error\n");
        return (1);
    }
    if (!ft_is_number(argv[1]))
    {
        ft_putstr("Error\n");
        return (1);
    }
    num = atoi(argv[1]);
    if (num < 0)
    {
        ft_putstr("Error\n");
        return (1);
    }
    number_to_words(num);
    return (0);
}
