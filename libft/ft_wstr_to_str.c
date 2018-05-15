/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:26:24 by egoodale          #+#    #+#             */
/*   Updated: 2018/05/15 14:27:44 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wstr_to_str(wchar_t *ws)
{
	char	*ret;
	size_t	i;
	size_t	pos;

	i = 0;
	pos = 0;
	ret = ft_strnew(ft_wstrlen(ws));
	while (ws[i])
	{
		ft_str_to_unicode(ws[i], ret + pos);
		pos += ft_wchrlen(ws[i]);
		i++;
	}
	return (ret);
}
