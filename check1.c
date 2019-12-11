/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:22:33 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/11 04:06:14 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int checkflagstwo(char *fmt, t_flag *t)
{
    int i = t->i;
    if (fmt[i + 1] == 'p')
        print_p(t, va_arg(t->args, void *));
    else if (fmt[i + 1] == 'x' | fmt[i + 1] == 'X')
        print_hexa(t, va_arg(t->args, int), fmt[i + 1]);
    else if (fmt[i + 1] == 'u')
        print_u(t, va_arg(t->args, unsigned int));
    else
        checkpresicion(fmt, t);
    return (t->i);
}

int checkflags(char *fmt, t_flag *t)
{
    int i;
    int y;
    int c;
    i = t->i;
    t->frmt = ft_strdup(fmt);
    get_flage(fmt, t);
    if (fmt[i + 1] == 'i' || fmt[i + 1] == 'd')
        c = print_di(t, va_arg(t->args, int));
    else if (fmt[i + 1] == 'c')
        c = print_c(t, va_arg(t->args, int));
    else if (fmt[i + 1] == 's')
        c = print_s(t, va_arg(t->args, char *));
    else if (fmt[i + 1] == '%')
        c = print_m(t);
    else
        c = checkflagstwo(fmt, t);
    return (c);
}