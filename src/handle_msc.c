/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_msc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 17:51:02 by egoodale          #+#    #+#             */
/*   Updated: 2018/05/04 18:17:15 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

intmax_t	*ft_printf_n_len(t_info *inf, va_list ap)
{
	if (inf->length == hh)
		return ((intmax_t *)va_arg(ap, signed char *));
	if (inf->length == h)
		return ((intmax_t *)va_arg(ap, short *));
	if (inf->length == l)
		return ((intmax_t *)va_arg(ap, long *));
	if (inf->length == ll)
		return ((intmax_t *)va_arg(ap, long long *));
	if (inf->length == j)
		return ((intmax_t *)va_arg(ap, intmax_t *));
	if (inf->length == z)
		return ((intmax_t *)va_arg(ap, ssize_t *));
	return ((intmax_t *)va_arg(ap, int *));
}

void    handle_pos(t_vector *vector, t_info *inf, va_list ap)
{
	intmax_t	*i;
	int			tmp;

	tmp = vector->len;
	i = ft_printf_n_len(inf, ap);
	*i = (intmax_t)tmp;
}


void    handle_percent(t_vector *vector, t_info *inf, va_list ap)
{
	char *str;

	(void)ap;
	str = ft_strnew(1);
	*str = *inf->spec;
	ft_pad_handle(inf, &str);
	ft_vector_append(vector, str);
	free(str);
}
