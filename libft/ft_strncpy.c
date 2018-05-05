/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:16:06 by egoodale          #+#    #+#             */
/*   Updated: 2018/02/22 10:12:46 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(const char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	char			*cpy;

	i = 0;
	cpy = (char *)dest;
	while (*(src + i) && i < n)
	{
		*(cpy + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(cpy + i) = '\0';
		i++;
	}
	return (cpy);
}
