/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 18:28:19 by egoodale          #+#    #+#             */
/*   Updated: 2018/02/20 17:53:56 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int pos;
	int len;

	i = 0;
	pos = 0;
	len = ft_strlen(to_find);
	if (!len)
		return ((char *)str);
	while (*(str + i))
	{
		while (*(to_find + pos) == *(str + i + pos))
		{
			if (pos == len - 1)
				return ((char *)str + i);
			pos++;
		}
		pos = 0;
		i++;
	}
	return (NULL);
}
