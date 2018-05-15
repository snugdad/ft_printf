/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:45:23 by egoodale          #+#    #+#             */
/*   Updated: 2018/05/15 13:28:54 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_vprintf(char **ret, const char *format, va_list ap)
{
	if (!*format)
		*ret = ft_strnew(0);
	if (!ret || !format || !*format)
		return (0);
	if (!ft_strchr(format, '%'))
	{
		if (!(*ret = ft_strdup(format)))
			return (-1);
		return (ft_strlen(*ret));
	}
	return (parse_f_string(ret, format, ap));
}

int		ft_printf(char *format, ...)
{
	va_list	ap;
	int		len;
	char	*ret;

	if (!format || !*format)
		return (0);
	va_start(ap, format);
	len = ft_vprintf(&ret, format, ap);
	write(1, ret, len);
	free(ret);
	ret = NULL;
	va_end(ap);
	return (len);
}
