#include <unistd.h>
#include <stdio.h>
char *ft_rev_print(char *str);
int main(int argc, char **argv)
{

	char *a = ft_rev_print(argv[1]);
	int i = 0 ;
	while (a[i] != '\0')
	{
	printf ("%c" , a[i]);
	i++;
	}
    return 0;
}
