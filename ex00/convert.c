#include <unistd.h>
#include <stdlib.h>

typedef struct s_dict
{
    unsigned long long number;
    char *word;
    struct s_dict *next;
} t_dict;

int is_space(char c);
int is_digit(char c);
unsigned long long ft_atoi(char *str);
void ft_putstr(char *str);
char *find_in_dict(t_dict *dict, unsigned long long n);

int is_valid_number(char *str)
{
    int i = 0;

    while (is_space(str[i]))
        i++;

    if (!str[i] || (!is_digit(str[i]) && str[i] != '+'))
        return 0;

    if (str[i] == '+')
        i++;

    if (!is_digit(str[i]))
        return 0;

    while (str[i])
    {
        if (!is_digit(str[i]) && !is_space(str[i]))
            return 0;
        i++;
    }

    return 1;
}

void convert_under_1000(t_dict *dict, unsigned long long n)
{
    if (n == 0)
        return;

    if (n >= 100)
    {
        unsigned long long hundreds = n / 100;
        char *hundred_word = find_in_dict(dict, hundreds);
        char *hundred = find_in_dict(dict, 100);

        if (hundred_word && hundred)
        {
            ft_putstr(hundred_word);
            write(1, " ", 1);
            ft_putstr(hundred);
        }

        n %= 100;
        if (n > 0)
            write(1, " ", 1);
    }

    if (n > 0)
    {
        if (n <= 20)
        {
            char *word = find_in_dict(dict, n);
            if (word)
                ft_putstr(word);
        }
        else
        {
            unsigned long long tens = (n / 10) * 10;
            unsigned long long units = n % 10;

            char *tens_word = find_in_dict(dict, tens);
            if (tens_word)
            {
                ft_putstr(tens_word);
                if (units > 0)
                {
                    write(1, " ", 1);
                    char *units_word = find_in_dict(dict, units);
                    if (units_word)
                        ft_putstr(units_word);
                }
            }
        }
    }
}

void convert_number(t_dict *dict, unsigned long long n)
{
    if (n == 0)
    {
        char *zero = find_in_dict(dict, 0);
        if (zero)
        {
            ft_putstr(zero);
            write(1, "\n", 1);
        }
        else
        {
            write(1, "Dict Error\n", 11);
        }
        return;
    }

    unsigned long long powers[] = {
        1000000000000000000ULL,
        1000000000000000ULL,
        1000000000000ULL,
        1000000000ULL,
        1000000ULL,
        1000ULL,
        1ULL};

    int first = 1;
    int i = 0;

    while (i < 7)
    {
        if (n >= powers[i])
        {
            unsigned long long part = n / powers[i];

            if (!first)
                write(1, " ", 1);

            if (part > 0)
            {
                if (powers[i] == 1)
                {
                    convert_under_1000(dict, part);
                }
                else
                {
                    convert_under_1000(dict, part);
                    write(1, " ", 1);
                    char *power_word = find_in_dict(dict, powers[i]);
                    if (power_word)
                    {
                        ft_putstr(power_word);
                    }
                    else
                    {
                        write(1, "Dict Error\n", 11);
                        return;
                    }
                }
                first = 0;
            }

            n %= powers[i];
        }
        i++;
    }

    write(1, "\n", 1);
}