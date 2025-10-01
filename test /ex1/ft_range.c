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
	int	len;

	if (min >= max)
		return (NULL);
	len = max - min;
	new = malloc(sizeof(int) * len);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = min + i;
		i++;
	}
	return (new);
}
