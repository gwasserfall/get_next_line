/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:35:38 by gwasserf          #+#    #+#             */
/*   Updated: 2019/05/28 16:36:38 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*new;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	new = ft_strnew(ft_strlen((char *)s));
	if (!new)
		return (NULL);
	while (*s)
	{
		new[i] = f(*s);
		s++;
		i++;
	}
	return (new);
}
