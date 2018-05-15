/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 13:18:18 by egoodale          #+#    #+#             */
/*   Updated: 2018/05/15 13:59:15 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_H
#	define FT_PRINTF_H

#include <stdarg.h>
#include "../libft/libft.h"
#define VALID_LEN_MOD(x) (x == 'h' || x == 'l' || x == 'z' || x == 'j' ? 1 : 0)
#define MAX_FORMATS 17
#define MAX(a, b) (a > b ? a : b)

typedef enum		e_lenmod
{
	hh,
	h,
	l,
	ll,
	j,
	z
}					t_lenmod;

typedef struct		s_arg
{
	char			flags;
	char			length;
	char			spec;
	int				width;
	int				prec;
	int				pset;
	int				rc;
}					t_arg;

typedef enum		e_flag
{
	L = 0x1,
	P = 0x2,
	S = 0x4,
	Z = 0x8,
	H = 0x10
}					t_flag;

int					ft_printf(char *format, ...);
int					ft_vprintf(char **ret, const char *format, va_list ap);
int					parse_f_string(char **ret, const char *format, va_list ap);
char				*get_next_arg(t_vector *vector, t_arg *inf,
									char **format, va_list ap);
void				init_arg(t_arg *inf);
int					valid_arg(char c);
void				handle_integer(t_vector *vector, t_arg *inf, va_list ap);
void				handle_strings(t_vector *vector, t_arg *inf, va_list ap);
void				handle_wstring(t_vector *vector, t_arg *inf, va_list ap);
void				handle_hexadec(t_vector *vector, t_arg *inf, va_list ap);
void				handle_unsigned(t_vector *vector, t_arg *inf, va_list ap);
void				handle_octal(t_vector *vector, t_arg *inf, va_list ap);
void				handle_chr(t_vector *vector, t_arg *inf, va_list ap);
void				handle_bin(t_vector *vector, t_arg *inf, va_list ap);
void				handle_pos(t_vector *vector, t_arg *inf, va_list ap);
void				handle_percent(t_vector *vector, t_arg *inf, va_list ap);
int					handle_color(t_vector *vector, t_arg *inf, char **format);
void				parse_unsigned(t_arg *inf, char **s);
void				parse_alt(t_arg *inf, char **s);
intmax_t			get_len_signed(char length, va_list ap);
uintmax_t			get_len_unsigned(char length, va_list ap);
void				get_flags(char **format, t_arg *inf);
void				get_lngth(char **format, t_arg *inf);
void				get_width(char **format, t_arg *inf, va_list ap);
void				get_preci(char **format, t_arg *inf, va_list ap);
void				add_padding(t_arg *inf, char **s);
void				add_prec_wstr(t_arg *pfinfo, wchar_t *str);
void				add_prec_num(t_arg *inf, char **s);
void				right_justify(t_arg *inf, char **s, char *new);

#	endif
