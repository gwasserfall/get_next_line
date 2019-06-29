/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:36:14 by gwasserf          #+#    #+#             */
/*   Updated: 2019/05/20 17:37:42 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int			index;
	const char	*source;
	char		*destination;

	index = 0;
	source = src;
	destination = dest;
	if (src == dest && n > 0)
		return (NULL);
	while (n-- > 0)
	{
		if (!(src == dest))
			destination[index] = source[index];
		index++;
	}
	return (dest);
}
