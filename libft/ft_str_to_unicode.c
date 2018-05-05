/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 16:02:21 by egoodale          #+#    #+#             */
/*   Updated: 2018/05/02 16:05:07 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_to_unicode(wchar_t c, char *s)
{
	if (c < (MB_CUR_MAX == 1 ? 0xFF : 0x7F))
				s[0] = (unsigned char)c;
	else if (c < (1 << 11))
	{
		s[0] = (unsigned char)((c >> 6) | 0xC0);
		s[1] = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 16))
	{
		s[0] = (unsigned char)(((c >> 12)) | 0xE0);
		s[1] = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		s[2] = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 21))
	{
		s[0] = (unsigned char)(((c >> 18)) | 0xF0);
		s[1] = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
		s[2] = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		s[3] = (unsigned char)((c & 0x3F) | 0x80);
	}
}