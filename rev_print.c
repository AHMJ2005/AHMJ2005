#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
char *ft_rev_print(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    char *a;
    a = (char *)malloc(sizeof(char) * i );
    int j = 0 ;
    int size = i;
    while ( j < size  ){
        a[j] = str[i]; 
        i--;
	j++;
    }
    a[j] = '\0';
    return a;
}
