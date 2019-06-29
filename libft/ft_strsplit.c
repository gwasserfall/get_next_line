/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 11:15:26 by gwasserf          #+#    #+#             */
/*   Updated: 2019/06/05 17:09:07 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(const char *s, char c)
{
	char	**array;
	int		str_index;
	int		arr_index;

	arr_index = 0;
	if (!s || !(array = ft_strarray(ft_wordcount((char *)s, c))))
		return (NULL);
	while (*s)
	{
		str_index = 0;
		if (*s != c && *s != '\0')
		{
			while (s[str_index] != c && s[str_index] != '\0')
				str_index++;
			array[arr_index] = ft_strnew(str_index + 1);
			ft_memcpy(array[arr_index], s, str_index);
			s += str_index - 1;
			arr_index++;
		}
		s++;
	}
	return (array);
}
