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
char *find_in_dict(t_dict *dict, unsigned long long n);
void convert_number(t_dict *dict, unsigned long long n);
int is_valid_number(char *str);
unsigned long long ft_atoi(char *str);
void ft_putstr(char *str);

int ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

void ft_putstr(char *str)
{
    int len = ft_strlen(str);
    int i = 0;
    while (i < len)
    {
        write(1, &str[i], 1);
        i++;
    }
}

int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' ||
            c == '\r' || c == '\f' || c == '\v');
}

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

unsigned long long ft_atoi(char *str)
{
    unsigned long long result = 0;
    int i = 0;

    while (is_space(str[i]))
        i++;

    while (is_digit(str[i]))
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result;
}

char *ft_strdup(char *str)
{
    int len = ft_strlen(str);
    char *new_str = malloc(len + 1);
    int i = 0;

    if (!new_str)
        return NULL;

    while (i < len)
    {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = '\0';
    return new_str;
}