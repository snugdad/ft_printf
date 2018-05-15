/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:54:21 by egoodale          #+#    #+#             */
/*   Updated: 2018/05/15 14:00:40 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_TRANSLATE_H
#	define FT_TRANSLATE_H

typedef void	(*t_printf)(t_vector *vector, t_arg *inf, va_list ap);

typedef struct	s_translator
{
	char		*type;
	t_printf	printf;
}				t_translator;

t_translator g_trans_list[] = {
	{"d", &handle_integer},
	{"i", &handle_integer},
	{"D", &handle_integer},
	{"s", &handle_strings},
	{"S", &handle_wstring},
	{"p", &handle_hexadec},
	{"x", &handle_hexadec},
	{"X", &handle_hexadec},
	{"u", &handle_unsigned},
	{"U", &handle_unsigned},
	{"c", &handle_chr},
	{"C", &handle_chr},
	{"o", &handle_octal},
	{"O", &handle_octal},
	{"b", &handle_bin},
	{"n", &handle_pos},
	{"%", &handle_percent}
};
#	endif
