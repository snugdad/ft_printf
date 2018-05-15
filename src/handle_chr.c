/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_chr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 20:46:43 by egoodale          #+#    #+#             */
/*   Updated: 2018/05/15 13:33:26 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_null_chr(t_vector *vector, char *s)
{
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(s);
	while (++i < len)
		*(s + i) = *(s + i) == 1 ? 0 : *(s + i);
	ft_vector_nappend(vector, s, len);
}

int		ft_handle_wchar(char **s, va_list ap)
{
	wchar_t	c;
	int		len;

	c = va_arg(ap, wchar_t);
	len = ft_wchrlen(c);
	*s = ft_strnew(len);
	ft_str_to_unicode(c, *s);
	return (c == '\0');
}

void	handle_chr(t_vector *vector, t_arg *inf, va_list ap)
{
	char	c;
	char	*s;
	int		null;

	if (inf->spec == 'C' || inf->length == l)
	{
		null = ft_handle_wchar(&s, ap);
		s[0] = null ? null : s[0];
	}
	else
	{
		c = va_arg(ap, int);
		s = ft_strnew(1);
		null = !c ? 1 : 0;
		s[0] = c + null;
	}
	add_padding(inf, &s);
	null ? ft_null_chr(vector, s) : ft_vector_append(vector, s);
	free(s);
}
