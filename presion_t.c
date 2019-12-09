/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presion_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:22:33 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/08 10:10:19 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int naas(int w, int p, t_flag *t)
{
    if (p > 0)
    {
        return (w - p - (p > t->size ? 0 : 1));
    }
    else
        return (w - t->size);
}

void pointer_pre(int w, t_flag *t, int p)
{
    if (w >= 0)
    {
        if (t->size < w || t->size < p)
        {
            if (p >= w)
                t->len += ft_putstr("0x") + print_zero(p - t->size + 2) + print_address_hex(t->p, &t->len, 2, t) - t->size - 1;
            else
                t->len += print_space((p > 0) ? (w - p - 3) : w - t->size) - t->size - 1 + ft_putstr("0x") + print_zero(p - t->size + 2) + print_address_hex(t->p, &t->len, 2, t) + 1;
        }
        else
        {
            t->len += ft_putstr("0x");
            if (t->p != 0 && p == 0)
                print_address_hex(t->p, &t->len, 2, t);
            else
                t->len += 2;
        }
    }
    else
    {
        w *= -1;
        if (t->size < w || t->size < p)
        {
            ft_putstr("0x");
            if (p >= w)
                t->len += print_zero(p - t->size + 2) + print_address_hex(t->p, &t->len, 2, t) - t->size - 1;
            else
                t->len += print_zero(p - t->size + 2) + print_address_hex(t->p, &t->len, 2, t) + print_space((p > 0) ? (w - p - 2) : w - t->size) - t->size - 1;
        }
        else
        {
            ft_putstr("0x");
            print_address_hex(t->p, &t->len, 2, t);
        }
    }
}

void hexa_presition(int w, int p, t_flag *t, char *fmt)
{
    int ts;
    if (w >= 0)
    {
        if (t->size < w || t->size < p)
        {
            if (p >= w)
            {
                ts += print_zero(p - t->size) + ((t->x == 0 && p == 0) ? zero_w(fmt, t, p, t->x, w) : print_hexa(t, t->x, t->flage)) - t->size - 1;
                t->len += (p > t->size ? p - t->size : t->size);
            }
            else
            {
                ts = print_space(naas(w, p, t)) + print_zero(p - t->size) + ((t->x == 0 && p == 0) ? zero_w(fmt, t, p, t->it, w) : print_hexa(t, t->x, t->flage) - t->size - 1);
                t->len += (w > t->size ? w - t->size : t->size);
            }
        }
        else
            ((t->x == 0 && p == 0) ? zero_w(fmt, t, p, t->x, w) : print_hexa(t, t->x, t->flage));
    }
    else
    {
        w *= -1;
        if (t->size < w || t->size < p)
        {
            if (p >= w)
            {
                ts += print_zero(p - t->size) + ((t->x == 0 && p == 0) ? zero_w(fmt, t, p, t->x, w) : print_hexa(t, t->x, t->flage)) - t->size - 1;
                t->len += (p > t->size ? p - t->size : t->size);
            }
            else
            {
                ts += print_zero(p - t->size) + ((t->x == 0 && p == 0) ? zero_w(fmt, t, p, t->x, w) : print_hexa(t, t->x, t->flage)) + print_space(naas(w, p, t)) - t->size - 1;
                t->len += (w > t->size ? w - t->size : t->size);
            }
        }
        else
            ((t->x == 0 && p == 0) ? zero_w(fmt, t, p, t->x, w) : print_hexa(t, t->x, t->flage));
    }
}