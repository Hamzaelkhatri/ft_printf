/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:08:51 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/08 12:46:45 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_neg(int *it, int w)
{
    if (*it < 0)
    {
        ft_putchar('-');
        *it *= -1;
        return (0);
    }
    return (0);
}

int print_tr(int u, int p, int w, int size)
{
    int y;
    int l;

    y = 0;
    l = 0;
    // printf("%i %i", size, p);
    if (p >= 0)
    {
        y = (u >= 0 ? w - p : w - p - 1);
        l = (u < 0 ? 0 : 1);
        return (print_space((size > p ? w - size - 1 : w - p - (w > p ? 0 : 1))));
    }
    else
    {
        l = (u <= 0 ? 0 : 1);
        return (print_space(0));
    }
}

int zero_w(char *fmt, t_flag *t, int p, int s, int w)
{
    int i;

    i = t->i + 1;
    while (fmt[i])
    {
        if (ft_strchr(".", fmt[i]))
        {
            i = -1;
            break;
        }
        else
            i++;
    }
    if (i == -1 && (s == 0) && p == 0)
    {
        if (w != 0)
        {
            ft_putchar(' ');
            t->len++;
        }
    }
    else if (s == 0 && w != 0 && i != -1)
        ft_putchar('0');
    else if (s != -100)
        ft_putchar(' ');
    return (i);
}

void print_unsigned(char *fmt, t_flag *t, int w, int p)
{
    int ts;
    if (w >= 0)
    {
        if (t->size < w || t->size < p)
        {
            if (p >= w)
            {
                ts = print_zero((p > t->size ? p - t->size : t->size)) + ((t->u == 0 && p == 0) ? zero_w(fmt, t, p, t->u, w) : print_u(t, t->u));
                t->len += (t->size > p ? 0 : p - t->size) + (t->u == 0 && p == 0 ? 1 : 0);
            }
            else
            {
                ts += print_space(w > t->size ? w - (p > t->size ? p : t->size) : t->size) + print_zero(p - t->size) + ((t->u == 0 && p == 0) ? zero_w(fmt, t, p, t->u, w) : print_u(t, t->u));
                t->len += (t->size > w ? 0 : w - t->size) + (t->u == 0 ? 1 : 0);
            }
        }
        else
            ((t->u == 0 && p == 0) ? zero_w(fmt, t, p, t->u, w) : print_u(t, t->u));
    }
    else
    {
        w *= -1;
        if (t->size < w || t->size < p)
        {
            if (p >= w)
            {
                ts = print_zero(p - t->size) + ((t->u == 0 && p == 0) ? zero_w(fmt, t, p, t->u, w) : print_u(t, t->u));
                t->len += (t->size > p ? 0 : p - t->size);
            }
            else
            {
                ts += print_zero(p - t->size) + ((t->u == 0 && p == 0) ? zero_w(fmt, t, p, t->u, w) : print_u(t, t->u)) + print_space(w > t->size ? w - (p > t->size ? p : t->size) : t->size);
                t->len += (t->size > w ? 0 : w - t->size);
            }
        }
        else
            ((t->u == 0 && p == 0) ? zero_w(fmt, t, p, t->u, w) : print_u(t, t->u));
    }
}

void print_intger(char *fmt, t_flag *t, int w, int p)
{
    int y;
    int ts;

    y = 0;
    y = t->it;

    if (w >= 0)
    {
        // printf("[%i]", t->size);
        if (t->size < w || t->size < p)
        {
            if (p > w)
            {
                ts = print_neg(&t->it, w) + print_zero((p > t->size ? p - t->size : 0) + (y >= 0 ? 0 : 1)) + ((t->it == 0 && p == 0) ? zero_w(fmt, t, p, t->it, w) : print_di(t, t->it));
                t->len += (p > t->size ? p - t->size : 0) + (y >= 0 ? 0 : 2);
            }
            else
            {
                ts = print_space(w > t->size ? w - (p > t->size ? p - (y >= 0 ? 0 : -1) : t->size) : t->size) + print_neg(&t->it, w) + print_zero((p > t->size ? p - t->size : p - w) + (y >= 0 ? 0 : 1)) + ((t->it == 0 && p == 0) ? zero_w(fmt, t, p, t->it, w) : print_di(t, t->it));
                t->len += (w > t->size ? w - t->size : 0) + (y >= 0 ? 0 : 2);
            }
        }
        else
        {
            ((t->it == 0 && p == 0) ? zero_w(fmt, t, p, t->it, w) : print_di(t, t->it));
        }
    }
    else
    {
        w *= -1;
        if (t->size < w || t->size < p)
        {

            if (p > w)
            {
                ts = print_neg(&t->it, w) + print_zero((p > t->size ? p - t->size : 0) + (y >= 0 ? 0 : 1)) + ((t->it == 0 && p == 0) ? zero_w(fmt, t, p, t->it, w) : print_di(t, t->it)) + ((t->it == 0 && p == 0) ? zero_w(fmt, t, p, t->it, w) : 0);
                t->len += (p > t->size ? p - t->size : 0) + (y >= 0 ? 0 : 2);
            }
            else
            {
                ts = print_neg(&t->it, w) + print_zero((p > t->size ? p - t->size : p - w) + (y >= 0 ? 0 : 1)) + ((t->it == 0 && p == 0) ? zero_w(fmt, t, p, t->it, w) : print_di(t, t->it)) + print_space(w > t->size ? w - (p > t->size ? p - (y >= 0 ? 0 : -1) : t->size) : t->size);
                t->len += (w > t->size ? w - t->size : 0) + (y >= 0 ? 0 : 1);
            }
        }
        else
        {
            ((t->it == 0 && p == 0) ? zero_w(fmt, t, p, t->it, w) : print_di(t, t->it));
        }
    }
}

char *ft_itoa_base(int value, int base, int c)
{
    char *ret;
    char *tab_base;
    int taille;
    int i;

    if (value < 0)
        value = -value;
    if (value == 0)
        return ("0");
    tab_base = (char *)malloc(sizeof(char) * 17);
    if (c == 'X')
        tab_base = "0123456789ABCDEF";
    else
        tab_base = "0123456789abcdef";
    taille = digit_count(value, base);
    ret = calloc(taille, 1);
    i = 1;
    while (value != 0)
    {
        ret[taille - i++] = tab_base[value % base];
        value /= base;
    }
    return (ret);
}

char *ft_to_hexa(unsigned int num, char c, int i)
{
    unsigned int num1;
    int cnt;
    char *str;

    if (i > 0)
        ft_itoa_base(i, 16, c);
    num1 = num;
    cnt = 1;
    while (num1 > 15)
    {
        num1 /= 16;
        cnt++;
    }
    str = (char *)malloc(sizeof(char) * (cnt + 1));
    str[cnt--] = '\0';
    while (cnt >= 0)
    {
        if ((num % 16) >= 10 && c == 'x')
            str[cnt--] = ((num % 16) % 10) + 'a';
        else if ((num % 16) >= 10 && c == 'X')
            str[cnt--] = ((num % 16) % 10) + 'A';
        else
            str[cnt--] = (num % 16) + '0';
        num /= 16;
    }
    return (str);
}

int print_hexa(t_flag *t, long x, char cap)
{
    t->len += ft_strlen(ft_to_hexa(x, cap, x));
    ft_putstr(ft_to_hexa(x, cap, x));
    t->i++;
    return (t->len);
}