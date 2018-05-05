/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:26:22 by egoodale          #+#    #+#             */
/*   Updated: 2018/02/22 20:18:43 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	num;

	sign = 1;
	num = 0;
	while (WHITE_S(*str) || W_PC(*str))
		str++;
	if (*str == '+')
	{
		str++;
		if (!(*str >= '0' && *str <= '9'))
			return (0);
	}
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while ((*str <= '9' && *str >= '0'))
	{
		num = num * 10 + *(str++) - '0';
		if (num >= LONG_MAX)
			return (sign == -1 ? 0 : -1);
	}
	return (sign * num);
}
