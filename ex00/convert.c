int ft_strlen(const char *s);
void ft_putstr(const char *s);
int ft_is_number(char *s);

static char *ones[] = {
    "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

static char *tens[] = {
    "", "", "twenty", "thirty", "forty",
    "fifty", "sixty", "seventy", "eighty", "ninety"};

void number_to_words(int n)
{
    if (n < 20)
        ft_putstr(ones[n]);
    else if (n < 100)
    {
        ft_putstr(tens[n / 10]);
        if (n % 10)
        {
            write(1, " ", 1);
            ft_putstr(ones[n % 10]);
        }
    }
    else if (n < 1000)
    {
        ft_putstr(ones[n / 100]);
        write(1, " hundred", 8);
        if (n % 100)
        {
            write(1, " ", 1);
            number_to_words(n % 100);
        }
    }
    else if (n < 1000000)
    {
        number_to_words(n / 1000);
        write(1, " thousand", 9);
        if (n % 1000)
        {
            write(1, " ", 1);
            number_to_words(n % 1000);
        }
    }
    else
        ft_putstr("too big");
    write(1, "\n", 1);
}
