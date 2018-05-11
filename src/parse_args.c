/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:14:42 by egoodale          #+#    #+#             */
/*   Updated: 2018/05/10 18:44:25 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/ft_translate.h"

int  valid_arg(char c)
{
    return(c == 'd' || c == 'i' || c == 'D' || c == 's' ||
           c == 'S' || c == 'p' || c == 'x' || c == 'X' ||
           c == 'o' || c == 'O' || c == 'b' || c == 'n' ||
           c == '%');
}

void init_arg(t_arg *inf)
{
    inf->flags = 0;
    inf->length = -1;
    inf->width = 0;
    inf->prec = -1;
    inf->pset = 0;
    inf->rc = 0;
}

char *get_next_arg(t_vector *vector, t_arg *inf, char **format, va_list ap) 
{
    while (*(*format + inf->rc))
    {
        if (*(*format + inf->rc) == '%')
        {
            ft_vector_nappend(vector, *format, inf->rc);
            inf->rc++;
            while(VALID_FLAG(*(*format + inf->rc)))
                get_flags(format, inf);
            get_width(format, inf, ap);
            get_preci(format, inf, ap);
            get_lngth(format, inf);
            return(*format + inf->rc);
        }
        if(*(*format + inf->rc) == '{' && !handle_color(vector, inf, format))
            inf->rc++;
        else
            inf->rc++;
    }
    ft_vector_nappend(vector, *format, inf->rc);
    return (NULL);
}

int  parse_f_string(char **ret, const char *format, va_list ap)
{
    size_t i;
    t_vector vector;
    t_arg inf;

    init_arg(&inf);
    if (ft_vector_init(&vector, ft_strlen(format) + 50) == -1)
        return (-1);
    while ((format = get_next_arg(&vector, &inf, (char **)&format, ap)))
    {
        i = -1;
        inf.spec = *format;
        while (++i < MAX_FORMATS)
            if (g_trans_list[i].type[0] == inf.spec)
            {
                g_trans_list[i].printf(&vector, &inf, ap);
                format++;
            }
        if(!valid_arg(inf.spec) && inf.width)
            ft_vector_append(&vector, ft_strfill(ft_strnew(inf.width - 1), ' ', inf.width - 1));
        init_arg(&inf);
    }
    *ret = ft_strndup(vector.data, vector.len);
    ft_vector_free(&vector);
    return (vector.len);
}