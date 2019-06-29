/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:38:24 by gwasserf          #+#    #+#             */
/*   Updated: 2019/05/20 18:16:44 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int val, size_t length)
{
	char	*ptr;
	int		index;

	index = 0;
	ptr = dest;
	while (length-- > 0)
	{
		ptr[index] = val;
		index++;
	}
	return (dest);
}
