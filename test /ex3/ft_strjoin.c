/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabujwei <aabujwei@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:41:34 by aabujwei          #+#    #+#             */
/*   Updated: 2025/09/29 16:17:45 by aabujwei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
int len_sep(char *sep)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
	{
		i++;
	}
	return (i);
}

int the_size_of_arrayex(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
char	*ft_strjoin(int size, char **strs, char *sep)
{
	int	word;
	int	i;
	char	*p;
	int	TSOAX;
	int	sizee;

	TSOAX = 0;
	word = size;
	i = 0;
	sizee = 0;
	//printf("%d" , sizee);
	if (size == 0)
	{
		*p = '\0';
		return (p);
	}
	while (i < size)
	{
		printf("%c\n" , strs[i][0]);
		TSOAX += the_size_of_arrayex(strs[i]);
		i++;
	}
	sizee = (((size - 1) * (len_sep(sep))) + TSOAX);
	printf("%d" , sizee);
}
int main()
{
	char **str;
	char a[] = ", ";
	str[0] = "aaa";
	str[1] = "www";
	str[2] = "qqq";
	ft_strjoin(3 , str, a);
return 0;
}
