/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 10:15:02 by egoodale          #+#    #+#             */
/*   Updated: 2018/02/22 17:31:46 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	len;
	char	*ret;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n == 0)
		ret[0] = '0';
	if (n < 0)
	{
		ret[0] = '-';
		n = -n;
	}
	ret[len] = '\0';
	while (n)
	{
		len--;
		ret[len] = (n % 10) + '0';
		n /= 10;
	}
	return (ret);
}
