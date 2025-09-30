#include <unistd.h>
#include <stdio.h>
int main(int argc , char **argv)
{
	(void)argc;
	(void)argv;
	int i = 0;
	char *a;
	a = argv[1];
	if(argc > 2)
		write (1 , "\n" , 1);
	else 
	{
		while (a[i] != '\0')
		{
		if (a[i] >= 'a' && a[i] <= 'z' )
		{
			a[i] -= 32;
		}else if(a[i] >= 'A' && a[i] <= 'Z')
		{
			a[i] += 32;
		}
		i++;
		}
		a[i] = '\0';
	}
	int j =0 ;
	while (a[j] != '\0')
	{
		write(1 , &a[j] , 1);
		j++;
	}
	return 0;
}
