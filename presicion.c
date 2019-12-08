/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presicion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:22:33 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/06 10:32:05 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int get_number(char *fmt, int *i, t_flag *t)
{
    char *nbr;
    int o;
    int j;
    int c = *i;
    o = 1;
    j = 0;

    while (!ft_strchr("cspdiuxX%%", fmt[c]))
    {
        if (fmt[c] == '-')
            o = -1;
        if (ft_strchr("*", fmt[c]))
        {
            *i = c + 1;
            return (o * va_arg(t->args, int));
        }
        c++;
    }
    c = *i;
    nbr = calloc(19, 1); //ft_calloc
    nbr[0] = '0';
    while (fmt[c] != '.' && fmt[c] != '\0' && !ft_strchr("cspdiuxX%%", fmt[c]))
    {
        nbr[j] = fmt[c];
        c++;
        j++;
    }
    if (fmt[c] == '.')
        c++;
    *i = c;
    return (ft_atoi(nbr));
}

int checkneg(char *fmt, t_flag *t)
{
    int i;
    i = t->i;
    while (!ft_strchr("cspdiuxX%%", fmt[i]))
    {
        if (ft_strchr(".", fmt[i]))
            return (0);
    }
    return (1);
}

int Checkpresicion(char *fmt, t_flag *t)
{
    int i;
    char *tr;
    i = t->i;
    if (fmt[i + 1] == '0')
    {
        presion_zero(fmt, t);
    }
    else
        presionpoint(fmt, t);
    return (0);
}