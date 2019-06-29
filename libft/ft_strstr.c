/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:41:06 by gwasserf          #+#    #+#             */
/*   Updated: 2019/06/24 14:27:23 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int len;
	int index;

	index = 0;
	len = ft_strlen(needle);
	if (len == 0 || (haystack == needle))
		return ((char *)haystack);
	while (*haystack)
	{
		while (needle[index] != 0)
		{
			if (needle[index] != *(haystack + index))
				break ;
			if (index == len - 1)
				return ((char *)haystack);
			index++;
		}
		haystack++;
		index = 0;
	}
	return (NULL);
}
