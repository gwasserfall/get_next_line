/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 11:06:20 by gwasserf          #+#    #+#             */
/*   Updated: 2019/06/05 10:37:59 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_cpyback(char *dest, const char *src, size_t n)
{
	while (n > 0)
	{
		n--;
		*(dest + n) = *(src + n);
	}
}

static void	ft_cpyfront(char *dest, const char *src, size_t n)
{
	while (*src && (n--))
	{
		*dest = *src;
		dest++;
		src++;
	}
	while (n > 0)
	{
		*dest = '\0';
		dest++;
		n--;
	}
}

char		*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t len;

	len = ft_strlen((char *)src);
	if (len > n)
	{
		ft_cpyback(dest, src, n);
	}
	else
	{
		ft_cpyfront(dest, src, n);
	}
	return (dest);
}
