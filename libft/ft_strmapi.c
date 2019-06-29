/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:36:41 by gwasserf          #+#    #+#             */
/*   Updated: 2019/05/28 16:37:23 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
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
		new[i] = f(i, *s);
		s++;
		i++;
	}
	return (new);
}
