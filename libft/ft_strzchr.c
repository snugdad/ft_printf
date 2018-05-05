/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strzchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:15:31 by egoodale          #+#    #+#             */
/*   Updated: 2018/05/01 17:15:35 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strzchr(const char *s, int c)
{
	int				i;
	unsigned char	a;

	a = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == a)
			return (i);
		i++;
	}
	if (s[i] == a)
		return (ft_strlen(s) + 1);
	return (0);
}