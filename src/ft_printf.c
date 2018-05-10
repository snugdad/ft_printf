/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:45:23 by egoodale          #+#    #+#             */
/*   Updated: 2018/05/10 16:23:08 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../ft_translate.h"

int  valid_arg(char c)
{
    return(c == 'd' || c == 'i' || c == 'D' || c == 's' ||
           c == 'S' || c == 'p' || c == 'x' || c == 'X' ||
           c == 'o' || c == 'O' || c == 'b' || c == 'n' ||
           c == '%');
}

char *get_next_arg(t_vector *vector, t_info *inf, char **format, va_list ap) 
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

void init_info(t_info *inf)
{
    inf->flags = 0;
    inf->length = -1;
    inf->width = 0;
    inf->prec = -1;
    inf->pset = 0;
    inf->rc = 0;
}

int  parse_f_string(char **ret, const char *format, va_list ap)
{
    size_t i;
    t_vector vector;
    t_info inf;

    init_info(&inf);
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
        init_info(&inf);
    }
    *ret = ft_strndup(vector.data, vector.len);
    ft_vector_free(&vector);
    return (vector.len);
}

int ft_vprintf(char **ret, const char *format, va_list ap)
{
    if (!*format)
        *ret = ft_strnew(0);
    if (!ret || !format || !*format)
        return (0);
    if (ft_strchr(format, '%') == NULL)
    {
        if (!(*ret = ft_strdup(format)))
            return (-1);
        return (ft_strlen(*ret));
    }
    return (parse_f_string(ret, format, ap));
}
int ft_printf(char *format, ...)
{
    va_list ap;
    int len;
    char *ret;

    if (!format || !*format)
        return (0);
    va_start(ap, format);
    len = ft_vprintf(&ret, format, ap);
    write(1, ret, len);
    free(ret);
    ret = NULL;
    va_end(ap);
    return (len);
}
