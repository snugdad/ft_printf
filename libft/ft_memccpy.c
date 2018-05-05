/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:10:19 by egoodale          #+#    #+#             */
/*   Updated: 2018/02/23 14:28:03 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*tmp_dest;
	size_t			i;

	tmp_dest = dest;
	i = -1;
	while (++i < n)
	{
		*(tmp_dest + i) = *((unsigned char*)src + i);
		if (*((unsigned char *)src + i) == (unsigned char)c)
			return (dest + i + 1);
	}
	return (NULL);
}
