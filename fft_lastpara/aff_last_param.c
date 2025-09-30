#include <unistd.h>
int main (int argc , char **argv)
{
	int i= 0 ;
	while (argv[argc - 1][i] != '\0')
	{
		write (1 , &argv[argc - 1 ][i] , 1);
		i++;
	}
	return 0;
}
