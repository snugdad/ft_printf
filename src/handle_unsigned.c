/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 13:40:49 by egoodale          #+#    #+#             */
/*   Updated: 2018/05/10 19:47:59 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void    handle_hexadec(t_vector *vector, t_arg *inf, va_list ap)
{
	uintmax_t	hex;
	char		*s;

	if (inf->spec == 'p')
		inf->length = j;
	hex = get_len_unsigned(inf->length, ap);
	s = ft_uimaxtoa_base(hex, 16, BASE_16);
	if (inf->spec == 'p' && inf->flags & Z && inf->pset)
		inf->flags ^= Z;
	parse_unsigned(inf, &s);
	ft_vector_append(vector, s);
	free(s);
}

void		handle_unsigned(t_vector *vector, t_arg *inf, va_list ap)
{
	uintmax_t	uns;
	char		*s;

	if (inf->spec == 'U')
		inf->length = l;
	uns = get_len_unsigned(inf->length, ap);
	s = ft_uimaxtoa_base(uns, 10, BASE_10);
	parse_unsigned(inf, &s);
	ft_vector_append(vector, s);
	free(s);
}

void		handle_octal(t_vector *vector, t_arg *inf, va_list ap)
{
	uintmax_t	oct;
	char		*s;

	if (inf->spec == 'O')
		inf->length = l;
	oct = get_len_unsigned(inf->length, ap);
	s = ft_uimaxtoa_base(oct, 8, BASE_8);
	parse_unsigned(inf, &s);
	ft_vector_append(vector, s);
	free(s);
}

void    handle_bin(t_vector *vector, t_arg *inf, va_list ap)
{
	uintmax_t	bin;
	char		*s;

	bin = va_arg(ap, unsigned long long);
	s = ft_uimaxtoa_base(bin, 2, BASE_2);
	parse_unsigned(inf, &s);
	ft_vector_append(vector, s);
	free(s);
}
