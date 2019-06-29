/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 16:58:04 by gwasserf          #+#    #+#             */
/*   Updated: 2019/06/24 14:29:43 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarray(size_t size)
{
	char	**array;
	size_t	i;

	i = 0;
	if (!(array = (char **)malloc(size * sizeof(char *) + 1)))
		return (NULL);
	array[size] = NULL;
	return (array);
}
