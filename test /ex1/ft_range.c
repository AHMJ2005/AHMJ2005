/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabujwei <aabujwei@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:44:47 by aabujwei          #+#    #+#             */
/*   Updated: 2025/09/29 10:49:52 by aabujwei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*new;
	int	i;
	int	size;
	int	len;

	len = (max - min) - 1;
	if (min >= max)
		*new = NULL;
	new = malloc(len);
	i = 0;
	size = min;
	while (size < max)
	{
		new[i] = size + i;
		i++;
	}
	return (new);
}
