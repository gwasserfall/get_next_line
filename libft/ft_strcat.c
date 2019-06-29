/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:28:11 by gwasserf          #+#    #+#             */
/*   Updated: 2019/05/20 18:28:55 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int len;
	int ind;

	len = ft_strlen(dest);
	ind = 0;
	while (*src)
	{
		dest[len + ind] = *src;
		src++;
		ind++;
	}
	dest[len + ind] = '\0';
	return (dest);
}
