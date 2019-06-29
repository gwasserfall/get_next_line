/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:04:00 by event             #+#    #+#             */
/*   Updated: 2019/05/20 18:29:49 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int index;

	index = 0;
	while (1)
	{
		if (s[index] == c)
			return ((char *)&s[index]);
		if (s[index] == '\0')
			return (NULL);
		index++;
	}
	return (NULL);
}
