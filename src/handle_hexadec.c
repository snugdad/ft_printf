/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexadec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 13:40:49 by egoodale          #+#    #+#             */
/*   Updated: 2018/05/04 18:16:42 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
# define IS_X(a) (((unsigned)a | 32) - 97 == 23u)
# define IS_O(a) (((unsigned)a | 32) - 97 == 14u)
# define IS_D(a) (((unsigned)a | 32) - 97 == 3u)
# define IS_U(a) (((unsigned)a | 32) - 97 == 20u)
# define ISXO(a) ((IS_X(a)) || (IS_O(a)))

uintmax_t	ft_xou_len(char length, va_list ap)
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

void		ft_handle_alt(t_info *inf, char **s)
{
	char *new;

	if (!(ISXO(inf->spec) || *inf->spec == 'p' || *inf->spec == 'b'))
		return ;
	new = ft_strdup(*s);
	if (*inf->spec == 'p')
		ft_insert_str(&new, "0x");
	else if (inf->flags & HTG)
	{
		if (*inf->spec == 'b' && ft_strcmp("0", *s) &&
														ft_strcmp("\0", *s))
			ft_insert_str(&new, "0b");
		else if (IS_X(*inf->spec) && ft_strcmp("0", *s) &&
														ft_strcmp("\0", *s))
			ft_insert_str(&new, "0x");
		else if (IS_O(*inf->spec) && **s != '0')
			ft_insert_str(&new, "0");
	}
	free(*s);
	*s = new;
}

void		ft_handle_xou(char **s, t_info *inf)
{
	if (inf->flags & ZER && inf->prec == 0)
		inf->flags ^= ZER;
	if (inf->prec == 0 && !ft_strcmp(*s, "0"))
		**s = '\0';
	ft_prec_nums(inf, s);
	if (inf->flags & ZER && *inf->spec == 'p')
	{
		inf->width = MAX(inf->width - 2, 0);
		ft_pad_handle(inf, s);
	}
	else if (inf->flags & ZER && inf->flags & HTG && (IS_X(*inf->spec)
														|| *inf->spec == 'b'))
	{
		inf->width = MAX(inf->width - 2, 0);
		ft_pad_handle(inf, s);
	}
	ft_handle_alt(inf, s);
	if (!(inf->flags & ZER && inf->flags & HTG && (IS_X(*inf->spec)
								|| *inf->spec == 'p' || *inf->spec == 'b')))
		ft_pad_handle(inf, s);
    if(*inf->spec == 'X')
	    ft_str_toupper(*s);
}

void    handle_hexadec(t_vector *vector, t_info *inf, va_list ap)
{
	uintmax_t	hex;
	char		*s;

	if (*inf->spec == 'p')
		inf->length = j;
	hex = ft_xou_len(inf->length, ap);
	s = ft_uimaxtoa_base(hex, 16, "0123456789abcdef");
	if (*inf->spec == 'p' && inf->flags & ZER && inf->pset)
		inf->flags ^= ZER;
	ft_handle_xou(&s, inf);
	ft_vector_append(vector, s);
	free(s);
}

void		handle_unsigned(t_vector *vector, t_info *inf, va_list ap)
{
	uintmax_t	uns;
	char		*str;

	if (*inf->spec == 'U')
		inf->length = l;
	uns = ft_xou_len(inf->length, ap);
	str = ft_uimaxtoa_base(uns, 10, "0123456789");
	ft_handle_xou(&str, inf);
	ft_vector_append(vector, str);
	free(str);
}
void		handle_octal(t_vector *vector, t_info *inf, va_list ap)
{
	uintmax_t	oct;
	char		*s;

	if (*inf->spec == 'O')
		inf->length = l;
	oct = ft_xou_len(inf->length, ap);
	s = ft_uimaxtoa_base(oct, 8, "01234567");
	ft_handle_xou(&s, inf);
	ft_vector_append(vector, s);
	free(s);
}


void    handle_bin(t_vector *vector, t_info *inf, va_list ap)
{
	uintmax_t	binary;
	char		*s;

	binary = va_arg(ap, unsigned long long);
	s = ft_uimaxtoa_base(binary, 2, "01");
	ft_handle_xou(&s, inf);
	ft_vector_append(vector, s);
	free(s);
}