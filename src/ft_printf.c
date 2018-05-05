/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:45:23 by egoodale          #+#    #+#             */
/*   Updated: 2018/05/02 15:04:00 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../ft_translate.h"

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
            if (!*(*format + inf->rc)) //vector nappend ?
                return (NULL);
            return(*format + inf->rc);
        }
        inf->rc++;
    }
    ft_vector_nappend(vector, *format, inf->rc);
    return (NULL);
}

void init_info(t_info *inf, const char *format, int spec_init)
{
    inf->flags = 0;
    inf->length = -1;
    inf->width = 0;
    inf->prec = -1;
    if(spec_init)
        inf->spec = ft_strdup((char *)format);
    inf->pset = 0;
    inf->rc = 0;
}

int  parse_f_string(char **ret, const char *format, va_list ap)
{
    size_t i;
    t_vector vector;
    t_info inf;

    init_info(&inf, format, 1);
    if (ft_vector_init(&vector, ft_strlen(format) + 50) == FAILED)
        return (FAILED);
    while ((inf.spec = get_next_arg(&vector, &inf, &inf.spec, ap)))
    {
        i = -1;
        while (++i < MAX_FORMATS)
         if (g_trans_list[i].type[0] == *inf.spec)
         {
             g_trans_list[i].printf(&vector, &inf, ap);
             init_info(&inf, format, 0);
             inf.spec++;
         }
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
void ft_printf(char *format, ...)
{
    va_list ap;
    int len;
    char *ret;

    if (!format || !*format)
        return ;
    va_start(ap, format);
    len = ft_vprintf(&ret, format, ap);
    write(1, ret, len);
    va_end(ap);
    return;
}
