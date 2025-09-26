#include <unistd.h>
#include <stddef.h>

int ft_strlen(const char *s)
{
    size_t i = 0;
    while (s && s[i])
        i++;
    return (i);
}

void ft_putstr(const char *s)
{
    if (s)
        write(1, s, ft_strlen(s));
}

int ft_is_number(char *s)
{
    int i = 0;
    if (!s || !s[0])
        return (0);
    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return (0);
        i++;
    }
    return (1);
}
