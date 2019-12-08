/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presicion_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:22:33 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/08 04:00:21 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int searchprecision(char *fmt, t_flag *t)
{
    int i;
    i = t->i + 1;
    while (fmt[i] == '0')
    {
        i++;
    }
    while (!ft_strchr("dipxX%%", fmt[i]))
    {
        if (ft_strchr(".-", fmt[i]))
        {
            (fmt[i] == '-' && fmt[i - 1] == '0') ? t->i = i - 1 : 0;
            presionpoint(fmt, t);
            return (1);
        }
        i++;
    }
    return (0);
}

static void negative_val(int *it, t_flag *t)
{
    if (*it < 0)
    {
        *it *= -1;
        t->size += 1;
        ft_putchar('-');
    }
}

void presion_zero(char *fmt, t_flag *t)
{
    int i;
    int w;
    int d;

    d = 0;
    if (searchprecision(fmt, t) == 0)
    {
        if (t->flage == 'd' || t->flage == 'i' || t->flage == 'u')
        {
            i = t->i + 1;
            w = get_number(fmt, &i, t);
            if (t->flage == 'u')
            {
                t->u = va_arg(t->args, unsigned int);
                t->size = digit_count(t->u, 10);
            }
            else
            {
                t->it = va_arg(t->args, int);
                t->size = digit_count(t->it, 10);
                d = t->it;
            }
            negative_val(&t->it, t);
            print_zero(w - t->size + (d < 0 ? 1 : 0));
            t->len += (w > t->size) ? w - t->size + (d < 0 ? 1 : 0) + (d >= 0 ? 0 : 1) : 0;
            (t->flage == 'u') ? print_u(t, t->u) : print_di(t, t->it);
            t->i = i;
        }
        else if (t->flage == 'c' || t->flage == '%')
        {
            i = t->i + 1;
            w = get_number(fmt, &i, t);
            if (t->flage == 'c')
                t->c = va_arg(t->args, int);
            else
                t->c = '%';
            t->len += w;
            print_zero(w - 1);
            ft_putchar(t->c);
            t->i = i;
        }
        else if (t->flage == 's')
        {
            i = t->i + 1;
            w = get_number(fmt, &i, t);
            t->s = ft_strdup(va_arg(t->args, char *));
            t->size = (ft_strlen(t->s));
            t->len += (w > t->size) ? w : t->size;
            print_zero(w - t->size);
            ft_putstr(t->s);
            t->i = i;
        }
        else if (t->flage == 'p')
        {
            i = t->i + 1;
            w = get_number(fmt, &i, t);
            t->size = digit_count((uintptr_t)t->p, 16) + 2;
            t->p = va_arg(t->args, void *);
            ft_putstr("0x");
            print_zero(w - t->size);
            print_address_hex(t->p, &t->len, 2, t);
            t->i = i;
        }
        else if (t->flage == 'x' || t->flage == 'X')
        {
            i = t->i + 1;
            w = get_number(fmt, &i, t);
            t->x = va_arg(t->args, long);
            t->size = ft_strlen(ft_to_hexa(t->x, t->flage, t->x));
            print_zero((w > t->size) ? w - t->size : t->size);
            ft_putstr(ft_to_hexa(t->x, t->flage, t->x));
            t->len += (w > t->size) ? w : t->size;
            t->i = i;
        }
    }
}