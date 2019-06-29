/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:37:05 by event             #+#    #+#             */
/*   Updated: 2019/06/06 15:40:30 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		index;
	char	*src;
	char	*dest;

	src = (char *)s1;
	len = ft_strlen(src);
	index = 0;
	dest = ft_strnew(len);
	if (!dest)
		return (NULL);
	while (index < len)
	{
		dest[index] = s1[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
