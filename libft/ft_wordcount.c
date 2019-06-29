/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 11:16:23 by gwasserf          #+#    #+#             */
/*   Updated: 2019/06/05 16:54:38 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_wordcount(const char *str, char delim)
{
	int counter;

	counter = 0;
	while (*str)
	{
		if (*str != delim)
		{
			while ((*str != delim) && *str)
				str++;
			counter++;
		}
		if (*str)
			str++;
	}
	return (counter);
}
