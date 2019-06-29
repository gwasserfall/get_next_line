/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:15:17 by gwasserf          #+#    #+#             */
/*   Updated: 2019/06/24 13:00:52 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const char	*source;
	char		*destination;
	int			index;

	index = 0;
	source = src;
	destination = dest;
	while (n-- > 0)
	{
		destination[index] = source[index];
		if (source[index] == (char)c)
		{
			return ((void *)&destination[index + 1]);
		}
		index++;
	}
	return (NULL);
}
