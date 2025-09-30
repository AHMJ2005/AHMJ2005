#include <stdio.h>
char    *ft_strrev(char *str)
{
	int i =0 ;
	while (str[i] != '\0')
		i++;
	int last = i - 1;
	i = 0;
	while (last > i)
	{
		int temp = str[i];
		str[i] = str[last];
		str[last] = temp;
		last--;
		i++;
	}
	return str;
}
int main()
{
	char a[] = "ahmad";
	ft_strrev(a);
	printf("%s" , a);
return 0;
}
