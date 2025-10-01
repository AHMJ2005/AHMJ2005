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

int	len_sep(char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
		i++;
	return (i);
}

int	the_size_of_arrayex(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	total_size(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += the_size_of_arrayex(strs[i]);
		i++;
	}
	return (len + (size - 1) * len_sep(sep));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*p;

	if (size == 0)
	{
		p = malloc(1);
		if (!p)
			return (NULL);
		p[0] = '\0';
		return (p);
	}
	p = malloc(total_size(size, strs, sep) + 1);
	if (!p)
		return (NULL);
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			p[k] = strs[i][j];
			j++;
			k++;
		}
		j = 0;
		while (i < size - 1 && sep[j])
		{
			p[k] = sep[j];
			j++;
			k++;
		}
		i++;
	}
	p[k] = '\0';
	return (p);
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
