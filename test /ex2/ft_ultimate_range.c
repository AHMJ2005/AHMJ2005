/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabujwei <aabujwei@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:53:08 by aabujwei          #+#    #+#             */
/*   Updated: 2025/09/29 10:50:05 by aabujwei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int ft_ultimate_range(int **range, int min, int max)
{
	int *arr;
	int i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	arr = malloc(sizeof(int) * (max - min));
	if (!arr)
		return (-1);
	*range = arr;
	i = 0;
	while (i < max - min)
	{
		arr[i] = min + i;
		i++;
	}
	return (max - min);
}

int main(void)
{
	int i;
	int *tab;
	int min;
	int max;
	int s;

	min = 0;
	max = 5;
	s = ft_ultimate_range(&tab, min, max);
	printf("size = %d\n", s);
	if (tab != NULL)
	{
		i = 0;
		while (i < s)
		{
			printf("%d\n", tab[i]);
			i++;
		}
	}
	else
		printf("NULL\n");
	return (0);
}
