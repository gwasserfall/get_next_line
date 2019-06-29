/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:37:28 by gwasserf          #+#    #+#             */
/*   Updated: 2019/06/05 10:52:36 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *ptr;

	ptr = dest;
	ptr += ft_strlen(dest);
	if (n < 1)
		return (dest);
	while (n--)
	{
		if (*src)
		{
			*ptr = *src;
			src++;
			ptr++;
		}
	}
	*ptr = 0;
	return (dest);
}
