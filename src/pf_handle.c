/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 19:20:46 by egoodale          #+#    #+#             */
/*   Updated: 2018/05/02 18:00:48 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_prec_wstr(t_info *pfinfo, wchar_t *str)
{
	size_t count;
	size_t i;

	i = 0;
	count = 0;
	if (pfinfo->prec == -1)
		return ;
	if (ft_wstrlen(str) <= (size_t)pfinfo->prec)
		return ;
	while (str[i] && count <= (size_t)pfinfo->prec)
	{
		count += ft_wchrlen(str[i]);
		i++;
	}
	str[i - 1] = '\0';
}

void    ft_prec_nums(t_info *inf, char **s)
{
    char *new;
    char sign;
    char *orig;

    orig = *s;
    if (inf->prec == 0 && !ft_strcmp("0", *s))
    {
        **s = '\0';
        return ;
    }
    inf->prec = inf->prec == -1 ? 1 : inf->prec;
    if((size_t)inf->prec < ft_strlen(*s))
        return ;
    sign = (!ft_isdigit((*s)[0]) && *inf->spec == 'd') ? (*s)[0] : 0;
    if (sign)
        (*s)++;
    new = ft_strnew(inf->prec + !!sign);
    ft_memset(new + !!sign, '0', inf->prec - ft_strlen(*s));
    ft_strcpy(new + inf->prec - ft_strlen(*s) + !!sign, *s);
    new[0] = sign ? sign : new[0];
    free(orig);
    *s = new;
}

void	ft_prec_handle(t_info *inf, char **s)
{
	if (inf->prec == -1)
		return ;
	if (ft_strlen(*s) <= (size_t)inf->prec)
		return ;
	(*s)[inf->prec] = '\0';
}

void    ft_right_just(t_info *inf, char **s, char *new)
{
    char sign;

    sign = 0;
    if (inf->flags & ZER)
    {
        sign = (!ft_isdigit((*s)[0]) && *inf->spec == 'd') ? (*s)[0] : 0;
        ft_memset(new, '0', inf->width - ft_strlen(*s) + !!sign);
        if (sign)
        {
            new[0] = sign;
            (*s)[0] = '0';
        }
    }
    else
    {
        ft_memset(new, ' ', inf->width - ft_strlen(*s));
        if ((inf->flags & POS) && **s != '-')
		    new[inf->width - ft_strlen(*s)] = ((*s)[0] == '-') ? '-' : '+';
    }
    ft_strcpy(new + inf->width - ft_strlen(*s) + !!sign, *s + !!sign);
}

void    ft_pad_handle(t_info *inf, char **s)
{
    char *new;

    if (inf->width == 0 || ft_strlen(*s) >= (size_t)inf->width)
		return ;
	new = ft_strnew(inf->width);
    if (inf->flags & LFT)
    {
        ft_strcpy(new, *s);
        ft_memset(new + ft_strlen(*s), ' ', inf->width - ft_strlen(*s));
    }
    else
        ft_right_just(inf, s, new);
    free(*s);
    *s = new;
}