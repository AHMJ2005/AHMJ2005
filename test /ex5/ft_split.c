/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabujwei <aabujwei@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 09:44:53 by aabujwei          #+#    #+#             */
/*   Updated: 2025/09/29 16:22:40 by aabujwei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	find_charset(char ch, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (ch == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	nbr_of_word(char *str, char *charset)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (str[i] != '\0')
	{
		while (str[i] && find_charset(str[i], charset))
			i++;
		if (str[i] && !find_charset(str[i], charset))
		{
			nbr++;
			while (str[i] && !find_charset(str[i], charset))
				i++;
		}
	}
	return (nbr);
}

char	*add_char(char *str, char *charset, int *cc)
{
	char	*p;
	int		start;
	int		j;
	int		len;

	start = *cc;
	j = 0;
	len = 0;
	while (str[*cc] && !find_charset(str[*cc], charset))
	{
		(*cc)++;
		len++;
	}
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (j < len)
	{
		p[j] = str[start + j];
		j++;
	}
	p[j] = 0;
	return (p);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		cc;
	int		word;
	char	**p;

	i = 0;
	cc = 0;
	word = nbr_of_word(str, charset);
	p = (char **)malloc(sizeof(char *) * (word + 1));
	if (!p)
		return (NULL);
	while (str[cc])
	{
		while (str[cc] && find_charset(str[cc], charset))
			cc++;
		if (str[cc] && !find_charset(str[cc], charset))
		{
			p[i] = add_char(str, charset, &cc);
			i++;
		}
	}
	p[i] = 0;
	return (p);
}
