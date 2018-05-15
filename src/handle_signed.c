/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 16:30:48 by egoodale          #+#    #+#             */
/*   Updated: 2018/05/15 13:22:40 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

intmax_t	get_len_signed(char length, va_list ap)
{
	if (length == hh)
		return ((signed char)va_arg(ap, int));
	if (length == h)
		return ((short)va_arg(ap, int));
	if (length == l)
		return (va_arg(ap, long));
	if (length == ll)
		return (va_arg(ap, long long));
	if (length == j)
		return (va_arg(ap, intmax_t));
	if (length == z)
		return (va_arg(ap, ssize_t));
	return (va_arg(ap, int));
}

void		handle_integer(t_vector *vector, t_arg *inf, va_list ap)
{
	intmax_t	nb;
	char		*s;

	inf->length = inf->spec == 'D' ? l : inf->length;
	inf->spec = inf->spec == 'i' || inf->spec == 'D' ? 'd' : inf->spec;
	nb = get_len_signed(inf->length, ap);
	s = ft_imaxtoa(nb);
	if (inf->prec != -1 && inf->flags & Z)
		inf->flags ^= Z;
	if (inf->prec == 0 && !ft_strcmp("0", s))
		*s = '\0';
	if ((inf->flags & P || inf->flags & S) && s[0] != '-')
	{
		ft_insert_str(&s, (inf->flags & S) ? " " : "+");
		s[0] = ((inf->flags & P ? '+' : s[0]));
	}
	add_prec_num(inf, &s);
	add_padding(inf, &s);
	ft_vector_append(vector, s);
	free(s);
}
