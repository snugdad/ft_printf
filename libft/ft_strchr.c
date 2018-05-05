/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:18:51 by egoodale          #+#    #+#             */
/*   Updated: 2018/02/25 16:43:15 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	needle;
	int				len;

	len = ft_strlen(str);
	i = -1;
	needle = (unsigned char)c;
	if (needle == '\0' && str[len] == '\0')
		return ((char*)&str[len]);
	while (str[++i])
		if (str[i] == needle)
			return ((char *)&str[i]);
	return (NULL);
}
