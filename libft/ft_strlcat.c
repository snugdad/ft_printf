/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:56:00 by egoodale          #+#    #+#             */
/*   Updated: 2018/02/23 14:30:21 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	size_t		i;
	int			j;
	size_t		dest_len;
	size_t		src_len;

	i = ft_strlen(dest);
	j = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (dest_size < dest_len + 1)
		return (src_len + dest_size);
	if (dest_size > dest_len + 1)
	{
		while (i < dest_size - 1)
			*(dest + i++) = *(src + j++);
		*(dest + i) = '\0';
	}
	return (dest_len + src_len);
}
