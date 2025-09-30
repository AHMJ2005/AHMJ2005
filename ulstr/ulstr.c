#include <unistd.h>
#include <stdio.h>
int main(int argc , char **argv)
{
	(void)argc;
	(void)argv;
	int i = 0;
	char *a;
	a = argv[1];
	printf("%d" , argc);
	if(argc > 1)
		write (1 , "\n" , 1);
	//else 
	//{
		//write(1 , "aa", 2);
		while (a[i] != '\0')
		{
		if (a[i] >= 'a' && a[i] <= 'z' )
		{
			a[i] -= 32;
			//write(1, "H" , 1);
		}else if(a[i] >= 'A' && a[i] <= 'Z')
		{
			a[i] += 32;
			//write(1 , &argv[1][i] , 1);
		}
			//write(1 , &argv[1][i] , 1);
		i++;
		}
		a[i] = '\0';
	//}
	int j =0 ;
	while (a[j] != '\0')
	{
		write(1 , &a[j] , 1);
		j++;
	}
	return 0;
}
