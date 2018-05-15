/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 14:29:51 by egoodale          #+#    #+#             */
/*   Updated: 2018/05/15 13:35:47 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_null_str(t_arg *inf)
{
	char *temp;

	if (inf->prec >= 1 || inf->prec == -1)
	{
		temp = ft_strdup("(null)");
		if (inf->prec > 6)
			temp[6] = '\0';
		else
			temp[(inf->prec == -1) ? 6 : inf->prec] = '\0';
	}
	else
		temp = ft_strdup("");
	return (temp);
}

void	handle_wstring(t_vector *vector, t_arg *pfinfo, va_list ap)
{
	wchar_t *ctemp;
	char	*s;

	ctemp = va_arg(ap, wchar_t *);
	if (!ctemp)
		s = ft_null_str(pfinfo);
	else
	{
		ctemp = ft_wstrdup(ctemp);
		add_prec_wstr(pfinfo, ctemp);
		s = ft_wstr_to_str(ctemp);
		free(ctemp);
	}
	add_padding(pfinfo, &s);
	ft_vector_append(vector, s);
	free(s);
}

void	handle_strings(t_vector *vector, t_arg *inf, va_list ap)
{
	char *ctemp;
	char *s;

	if (inf->length == l)
	{
		handle_wstring(vector, inf, ap);
		return ;
	}
	ctemp = va_arg(ap, char *);
	s = !ctemp ? ft_null_str(inf) : ft_strdup(ctemp);
	if (!(inf->prec == -1 || (int)ft_strlen(s) <= inf->prec))
		s[inf->prec] = '\0';
	add_padding(inf, &s);
	ft_vector_append(vector, s);
	free(s);
}
