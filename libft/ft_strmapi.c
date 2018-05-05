/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 19:26:39 by egoodale          #+#    #+#             */
/*   Updated: 2018/02/22 20:24:42 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;
	int		i;

	i = -1;
	if (!f || !s || !(map = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (*(s + ++i))
		*(map + i) = f((unsigned int)i, *(s + i));
	return (map);
}
