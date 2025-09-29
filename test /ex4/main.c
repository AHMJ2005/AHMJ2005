int             ft_strlen(char *str);
int             ft_power(int n, int p);
char    *ft_putnbr_base(int nbr, char *base, int is_neg);
char *ft_convert_base(char *nbr , char *base_from , char *base_to);
char    *check_sign(char *str, int *is_neg);
int     check_valid(char *base);
char    *ft_atoi(char *str, char *base, int *is_neg, int *size);
#include <stdio.h>
int main()
{
        char a[] = "-QKqJkW";
        char base_from[] = "aQXekWLct7brEMUyTBzKCixg2OFnqS1IHAmslYP0Nh598fJVj";
       char base_to[] = "gTPnO1KrsheE5YfwZAjb4BS0cLyv2GpQRa3dtH";
        char *z = ft_convert_base(a ,base_from , base_to);
	printf ("%s" , z);
        return 0;
}

