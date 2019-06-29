/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwasserf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 09:00:12 by event             #+#    #+#             */
/*   Updated: 2019/06/24 11:44:42 by gwasserf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long result;
	long long sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str) || (*str == '+' && ft_isdigit(*(str + 1))))
		str++;
	if (*str == '-' && (sign = -1))
		str++;
	while (*str >= '0' && *(str) <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	result *= sign;
	return (int)result;
}
