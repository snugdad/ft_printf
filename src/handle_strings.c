/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 14:29:51 by egoodale          #+#    #+#             */
/*   Updated: 2018/05/10 16:05:00 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_null_str(t_info *inf)
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
void	handle_wstring(t_vector *vector, t_info *pfinfo, va_list ap)
{
	wchar_t *ctemp;
	char	*str;

	ctemp = va_arg(ap, wchar_t *);
	if (!ctemp)
		str = ft_null_str(pfinfo);
	else
	{
		ctemp = ft_wstrdup(ctemp);
		ft_prec_wstr(pfinfo, ctemp);
		str = ft_wstr_to_str(ctemp);
		free(ctemp);
	}
	ft_pad_handle(pfinfo, &str);
	ft_vector_append(vector, str);
	free(str);
}

void	handle_strings(t_vector *vector, t_info *inf, va_list ap)
{
	char *ctemp;
	char *str;

	if (inf->length == l)
	{
		handle_wstring(vector, inf, ap);
		return ;
	}
	ctemp = va_arg(ap, char *);
	if (!ctemp)
		str = ft_null_str(inf);
	else
		str = ft_strdup(ctemp);
	ft_prec_handle(inf, &str);
	ft_pad_handle(inf, &str);
	ft_vector_append(vector, str);
	free(str);
}
