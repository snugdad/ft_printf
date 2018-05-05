/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 22:41:15 by egoodale          #+#    #+#             */
/*   Updated: 2018/02/21 16:00:53 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	while (n && *s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return ((unsigned char)*(s1 - 1) - (unsigned char)*(s2 - 1));
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}
