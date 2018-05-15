/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:11:19 by egoodale          #+#    #+#             */
/*   Updated: 2018/05/15 14:23:06 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrdup(wchar_t *str)
{
	wchar_t	*dup;
	size_t	size;

	size = 0;
	while (str[size])
		++size;
	dup = (wchar_t *)malloc(sizeof(wchar_t) * (size + 1));
	if (!dup)
		return (NULL);
	size = 0;
	while (str[size])
	{
		dup[size] = str[size];
		size++;
	}
	dup[size] = '\0';
	return (dup);
}
