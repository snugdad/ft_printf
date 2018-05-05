/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:49:56 by egoodale          #+#    #+#             */
/*   Updated: 2018/02/21 16:20:06 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;

	if (*little)
	{
		while (*big && len != 0)
		{
			n = 0;
			while (*(big + n) == *(little + n) && n < len)
			{
				n++;
				if (!(*(little + n)))
					return ((char *)big);
			}
			big++;
			len--;
		}
		return (NULL);
	}
	else
		return ((char *)big);
}
