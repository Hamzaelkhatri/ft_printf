/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presionpoint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 11:21:07 by osamoile          #+#    #+#             */
/*   Updated: 2019/12/07 23:52:07 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void presionpoint_trime(char *fmt, t_flag *t)
{
    int i;
    int w;
    int p;
    i = t->i + 1;
    if (t->flage == 's')
    {
        w = get_number(fmt, &i, t);
        p = get_number(fmt, &i, t);
    }
}

void presionpoint_prime(char *fmt, t_flag *t)
{
    int i;
    int w;
    int p;
    i = t->i + 1;
    if (t->flage == 'p')
    {
        w = get_number(fmt, &i, t);
        p = get_number(fmt, &i, t);
        t->p = va_arg(t->args, void *);
        t->size = digit_count((uintptr_t)t->p, 16) + 2;
        pointer_pre(w, t, p);
        t->i = i;
    }
    else if (t->flage == 'x' || t->flage == 'X')
    {
        w = get_number(fmt, &i, t);
        p = get_number(fmt, &i, t);
        t->x = va_arg(t->args, long);
        t->size = ft_strlen(ft_to_hexa(t->x, t->flage, t->x));
        hexa_presition(w, p, t);
        t->i = i;
    }
    else
        presionpoint_trime(fmt, t);
}

void presionpoint(char *fmt, t_flag *t)
{
    int i;
    int w;
    int p;
    int d;

    i = t->i + 1;
    if (fmt[i + 1] == '-')
        i += zapper_neg(&fmt[i], 1);
    if (t->flage == 'd' || t->flage == 'i')
    {
        w = get_number(fmt, &i, t);
        p = get_number(fmt, &i, t);
        t->it = va_arg(t->args, int);
        t->size = digit_count(t->it, 10);
        print_intger(fmt, t, w, p);
        t->i = i;
    }
    else if (t->flage == 'c' || t->flage == '%')
    {
        w = get_number(fmt, &i, t);
        get_number(fmt, &i, t);
        (t->flage == 'c') ? printpresi_c(w, t, va_arg(t->args, int)) : printpresi_c(w, t, '%');
        t->i = i;
    }
    else if (t->flage == 'u')
    {
        w = get_number(fmt, &i, t);
        p = get_number(fmt, &i, t);
        t->u = va_arg(t->args, unsigned int);
        t->size = digit_count(t->u, 10);
        print_unsigned(fmt, t, w, p);
        t->i = i;
    }
    else
        presionpoint_prime(fmt, t);
}