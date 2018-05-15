/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mods.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:04:21 by egoodale          #+#    #+#             */
/*   Updated: 2018/05/15 13:26:57 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	get_flags(char **format, t_arg *inf)
{
	const char	flags[] = "-+ 0#";
	size_t		i;

	i = 0;
	while (flags[i] != *(*format + inf->rc) && flags[i])
		i++;
	if (flags[i])
	{
		inf->flags = inf->flags | (1 << i);
		++inf->rc;
	}
}

void	get_lngth(char **format, t_arg *inf)
{
	const char	lengths[] = "hhlljz";
	int			i;

	i = 0;
	if (VALID_LEN_MOD(*(*format + inf->rc)))
	{
		i = ft_strzchr(lengths, *(*format + inf->rc));
		if (i == 0)
		{
			if (*(*format + (inf->rc + 1)) == 'h')
				++inf->rc;
			else
				i = 1;
		}
		if (i == 2)
			i = *(*format + (inf->rc + 1)) == 'l' ? ll : l;
		inf->length = MAX(i, inf->length);
		inf->rc = inf->length == 3 ? inf->rc + 1 : inf->rc;
		inf->rc++;
	}
}

void	get_width(char **format, t_arg *inf, va_list ap)
{
	int res;

	res = 0;
	if (*(*format + inf->rc) == '*')
	{
		inf->width = va_arg(ap, int);
		if (inf->width < 0)
		{
			if (!(inf->flags & L))
				inf->flags ^= L;
			inf->width = -inf->width;
		}
		++inf->rc;
		return ;
	}
	if (!ft_isdigit(*(*format + inf->rc)))
		return ;
	while (ft_isdigit(*(*format + inf->rc)))
	{
		res = res * 10 + (*(*format + inf->rc) - '0');
		inf->rc++;
	}
	inf->width = res;
}

void	get_preci(char **format, t_arg *inf, va_list ap)
{
	int res;

	res = 0;
	if (*(*format + inf->rc) != '.')
		return ;
	inf->pset = true;
	inf->rc++;
	if (*(*format + inf->rc) == '*')
	{
		inf->prec = va_arg(ap, int);
		inf->prec = inf->prec < -1 ? -1 : inf->prec;
		inf->rc++;
		return ;
	}
	while (ft_isdigit(*(*format + inf->rc)))
	{
		res = res * 10 + (*(*format + inf->rc) - '0');
		inf->rc++;
	}
	inf->prec = res;
}
