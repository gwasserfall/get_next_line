/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 14:17:35 by gwasserf          #+#    #+#             */
/*   Updated: 2019/05/28 16:38:51 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	int		index;
	char	*newstr;

	newstr = ft_strnew(len);
	if (!newstr || !s)
		return (NULL);
	index = 0;
	s += (int)start;
	while (index < (int)len)
	{
		newstr[index] = *s;
		s++;
		index++;
	}
	return (newstr);
}
