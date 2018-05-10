/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 13:18:18 by egoodale          #+#    #+#             */
/*   Updated: 2018/05/10 15:07:32 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

#define VALID_FLAG(x) (x == '-' || x == '+' || x == '0' || x == '#' || x == ' ' ? 1 : 0)
#define VALID_LEN_MOD(x) (x == 'h' || x == 'l' || x == 'z' || x == 'j' ? 1 : 0)
#define MAX_FORMATS 17
#define SUCCESS 0
#define FAILED -1
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define BASE_16 "0123456789abcdef"
#define BASE_10 "0123456789"
#define BASE_8 "01234567"
#define BASE_2 "01"

typedef enum		e_bool
{
	false,
	true
} 					t_bool;

typedef enum		e_lenmod
{
	hh,
	h,
	l,
	ll,
	j,
	z
}				t_lenmod;

typedef struct	s_info
{
	char		flags;
	char		length;
	char		spec;
	int			width;
	int			prec;
	int			pset;
	int			rc;
}				t_info;

typedef enum	e_flag
{
	LFT = 1 << 0,
	POS = 1 << 1,
	INV = 1 << 2,
	ZER = 1 << 3,
	HTG = 1 << 4
}				t_flag;
//
int		ft_printf(char *format, ...);
//HANDLES
void	handle_integer(t_vector *vector, t_info *inf, va_list ap);
void	handle_strings(t_vector *vector, t_info *inf, va_list ap);
void	handle_wstring(t_vector *vector, t_info *inf, va_list ap);
void	handle_hexadec(t_vector *vector, t_info *inf, va_list ap);
void	handle_unsigned(t_vector *vector, t_info *inf, va_list ap);
void	handle_octal(t_vector *vector, t_info *inf, va_list ap);
void	handle_chr(t_vector *vector, t_info *inf, va_list ap);
void	handle_bin(t_vector *vector, t_info *inf, va_list ap);
void	handle_pos(t_vector *vector, t_info *inf, va_list ap);
void	handle_percent(t_vector *vector, t_info *inf, va_list ap);
int		handle_color(t_vector *vector, t_info * inf, char **format);
//UTILS
void   	get_flags(char **format, t_info *inf);
void   	get_lngth(char **format, t_info *inf);
void	get_width(char **format, t_info *inf, va_list ap);
void	get_preci(char **format, t_info *inf, va_list ap);

//STRING 
void    ft_pad_handle(t_info *inf, char **s);
void	ft_prec_wstr(t_info *pfinfo, wchar_t *str);
void	ft_prec_handle(t_info *inf, char **s);
void    ft_prec_nums(t_info *inf, char **s);
void    ft_right_just(t_info *inf, char **s, char *new);


#endif
