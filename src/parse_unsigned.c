/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 13:40:49 by egoodale          #+#    #+#             */
/*   Updated: 2018/05/15 13:25:12 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#define IS_X(c) ((c | 32) == 'x')
#define IS_O(c) ((c | 32) == 'o')
#define IS_D(c) ((c | 32) == 'd')
#define IS_U(c) ((c | 32) == 'u')
#define ISXO(c) ((IS_X(c)) || (IS_O(c)))

uintmax_t	get_len_unsigned(char length, va_list ap)
{
	if (length == hh)
		return ((unsigned char)va_arg(ap, int));
	if (length == h)
		return ((unsigned short)va_arg(ap, int));
	if (length == l)
		return (va_arg(ap, unsigned long));
	if (length == ll)
		return (va_arg(ap, unsigned long long));
	if (length == j)
		return (va_arg(ap, uintmax_t));
	if (length == z)
		return (va_arg(ap, size_t));
	return (va_arg(ap, unsigned int));
}

void		parse_alt(t_arg *inf, char **s)
{
	char *new;

	if (!(ISXO(inf->spec) || inf->spec == 'p' || inf->spec == 'b'))
		return ;
	new = ft_strdup(*s);
	if (inf->spec == 'p')
		ft_insert_str(&new, "0x");
	else if (inf->flags & H)
	{
		if (inf->spec == 'b' && ft_strcmp("0", *s) &&
				ft_strcmp("\0", *s))
			ft_insert_str(&new, "0b");
		else if (IS_X(inf->spec) && ft_strcmp("0", *s) &&
				ft_strcmp("\0", *s))
			ft_insert_str(&new, "0x");
		else if (IS_O(inf->spec) && **s != '0')
			ft_insert_str(&new, "0");
	}
	free(*s);
	*s = new;
}

void		parse_unsigned(t_arg *inf, char **s)
{
	if (inf->flags & Z && inf->prec == 0)
		inf->flags ^= Z;
	if (inf->prec == 0 && !ft_strcmp(*s, "0"))
		**s = '\0';
	add_prec_num(inf, s);
	if (inf->flags & Z && inf->spec == 'p')
	{
		inf->width = MAX(inf->width - 2, 0);
		add_padding(inf, s);
	}
	else if (inf->flags & Z && inf->flags & H && (IS_X(inf->spec)
				|| inf->spec == 'b'))
	{
		inf->width = MAX(inf->width - 2, 0);
		add_padding(inf, s);
	}
	parse_alt(inf, s);
	if (!(inf->flags & Z && inf->flags & H && (IS_X(inf->spec)
					|| inf->spec == 'p' || inf->spec == 'b')))
		add_padding(inf, s);
	if (inf->spec == 'X')
		ft_str_toupper(*s);
}
