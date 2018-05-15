/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:37:12 by egoodale          #+#    #+#             */
/*   Updated: 2018/05/15 14:24:30 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_unsigned(uintmax_t nb)
{
	if (nb == ULLONG_MAX)
		ft_putstr("18446744073709551616");
	else
	{
		if (nb >= 10)
			ft_putnbr_unsigned((nb / 10));
		ft_putchar((nb % 10) + '0');
	}
}
