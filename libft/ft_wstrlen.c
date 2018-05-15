/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:12:18 by egoodale          #+#    #+#             */
/*   Updated: 2018/05/15 14:15:38 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrlen(wchar_t *str)
{
	size_t count;
	size_t i;

	i = 0;
	count = 0;
	while (str[i])
	{
		count += ft_wchrlen(str[i]);
		i++;
	}
	return (count);
}
