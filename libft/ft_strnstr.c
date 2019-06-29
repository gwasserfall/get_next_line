/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:44:04 by gwasserf          #+#    #+#             */
/*   Updated: 2019/06/24 14:27:49 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ned, size_t len)
{
	int i;
	int j;

	if (hay == ned || !*ned)
		return ((char *)hay);
	i = 0;
	while (hay[i] && len--)
	{
		j = 0;
		while (hay[i + j] == ned[j])
		{
			if ((!hay[i + j] && !ned[j]) || !ned[j + 1])
				return ((char *)&hay[i]);
			if (!hay[i + j])
				break ;
			if (j >= (int)len)
				return (NULL);
			j++;
		}
		i++;
	}
	return (NULL);
}
