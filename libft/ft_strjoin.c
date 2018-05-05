/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:42:47 by egoodale          #+#    #+#             */
/*   Updated: 2018/02/21 21:08:51 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*u_str;
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = -1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(u_str = ft_strnew((s1_len + s2_len))))
		return (NULL);
	while (++i < s1_len)
		*(u_str + i) = *(s1 + i);
	while (++j < s2_len)
		*(u_str + i++) = *(s2 + j);
	return (u_str);
}
