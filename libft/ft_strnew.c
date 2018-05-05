/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:00:39 by egoodale          #+#    #+#             */
/*   Updated: 2018/02/21 20:20:23 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_str;

	if (!(new_str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(new_str, '\0', (size + 1));
	return (new_str);
}
