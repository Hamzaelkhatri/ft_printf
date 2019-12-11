/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:08:51 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/11 04:05:29 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *fmt, ...)
{
    int i;
    i = 0;
    t_flag t;
    int count = 0;
    va_list args;

    va_start(t.args, fmt);
    t.i = 0;
    while (fmt[t.i] != '\0')
    {
        if (fmt[t.i] == '%')
        {
            // checkflags((char *)fmt, t);
            if (fmt[i + 1] == 'k' | fmt[i + 1] == 'k')
            {
                int it = va_arg(args, int);
                count += digit_count(it, 10);
                ft_putnbr_fd(it, 1);
                count--;
                i++;
            }
            else if (fmt[i + 1] == 'c')
            {
                int c = va_arg(args, int);
                count += 1;
                ft_putchar(c);
                count--;
                i++;
            }
            else if (fmt[i + 1] == 's')
            {
                char *s = va_arg(args, char *);
                count += ft_strlen(s);
                ft_putstr(s);
                count--;
                i++;
            }
            else if (fmt[i + 1] == '%')
            {
                ft_putchar('%');
                i++;
            }
            else if (fmt[i + 1] == 'p')
            {
                void *p = va_arg(args, void *);
                print_address_hex(p);
                i++;
            }
            else if (fmt[i + 1] == 'x' | fmt[i + 1] == 'X')
            {
                int x = va_arg(args, int);
                count += ft_strlen(ft_to_hexa(x, fmt[i + 1], x));
                ft_putstr(ft_to_hexa(x, fmt[i + 1], x));
                count--;
                i++;
            }
            else if (fmt[i + 1] == 'u')
            {
                unsigned int u = va_arg(args, unsigned int);
                count += digit_count(u, 10);
                print_u(u);
                count--;
                i++;
            }
            else if (fmt[i + 1] == 39)
            {
                printf_flag(fmt, &i);
            }
            else if (fmt[i + 1] == '-')
            {
                int y = i + 2;
                int u = 0;
                char *tr = calloc(10, sizeof(char));
                while (fmt[y] != 'i' && fmt[y] != 'd' && fmt[y] != 'x' && fmt[y] != 'X' && fmt[y] != 'u' && fmt[y] != 'p' && fmt[y] != 's')
                {
                    tr[u] = fmt[y];
                    y++;
                    u++;
                }
                i = y;
                if (fmt[y] == 'i' || fmt[y] == 'd')
                {
                    int t = 0;
                    y = ft_atoi(tr);

                    int it = va_arg(args, int);
                    int co = digit_count(it, 10);
                    if (it < 0)
                    {
                        ft_putchar('-');
                        it *= -1;
                    }
                    else
                        count--;
                    if (it)
                        ft_putnbr_fd(it, 1);
                    while (co < y)
                    {
                        ft_putchar(' ');
                        y--;
                        t++;
                    }

                    count--;
                    count += y + t - u;
                }
                else if (fmt[y] == 's')
                {
                    y = ft_atoi(tr);
                    char *s = va_arg(args, char *);
                    ft_putnstr(s, y);
                    count--;
                    count -= u;
                }
                else if (fmt[y] == 'x' || fmt[y] == 'X')
                {
                    int t = 0;
                    int x = va_arg(args, int);
                    int co = ft_strlen(ft_to_hexa(x, fmt[i], x));
                    y = ft_atoi(tr);
                    count--;
                    if (y > 512)
                        y = 512;
                    while (co < y)
                    {
                        ft_putnbr_fd(0, 1);
                        y--;
                        t++;
                    }
                    ft_putstr(ft_to_hexa(x, fmt[i], x));
                    count--;
                    count += y + t - u;
                }
            }
            else if (fmt[i + 1] == '.')
            {
                int y = i + 2;
                int u = 0;
                char *tr = calloc(10, sizeof(char));
                while (fmt[y] != 'i' && fmt[y] != 'd' && fmt[y] != 'x' && fmt[y] != 'X' && fmt[y] != 'u' && fmt[y] != 'p' && fmt[y] != 's')
                {
                    tr[u] = fmt[y];
                    y++;
                    u++;
                }
                i = y;
                if (fmt[y] == 'i' || fmt[y] == 'd')
                {
                    int t = 0;
                    y = ft_atoi(tr);

                    int it = va_arg(args, int);
                    int co = digit_count(it, 10);
                    if (it < 0)
                    {
                        ft_putchar('-');
                        it *= -1;
                    }
                    else
                        count--;
                    if (y > 512)
                        y = 512;
                    while (co < y)
                    {
                        ft_putnbr_fd(0, 1);
                        y--;
                        t++;
                    }
                    if (it)
                        ft_putnbr_fd(it, 1);
                    count--;
                    count += y + t - u;
                }
                else if (fmt[y] == 's')
                {
                    y = ft_atoi(tr);
                    char *s = va_arg(args, char *);
                    ft_putnstr(s, y);
                    count--;
                    count -= u;
                }
                else if (fmt[y] == 'x' || fmt[y] == 'X')
                {
                    int t = 0;
                    int x = va_arg(args, int);
                    int co = ft_strlen(ft_to_hexa(x, fmt[i], x));
                    y = ft_atoi(tr);
                    count--;
                    if (y > 512)
                        y = 512;
                    while (co < y)
                    {
                        ft_putnbr_fd(0, 1);
                        y--;
                        t++;
                    }
                    ft_putstr(ft_to_hexa(x, fmt[i], x));
                    count--;
                    count += y + t - u;
                }
            }
            else if (ft_isdigit(fmt[i + 1]))
            {
                int c = i + 1;
                int y = 0;
                char *tr = calloc(10, sizeof(char));

                while (ft_isdigit(fmt[c]))
                {
                    tr[y] = fmt[c];
                    c++;
                    y++;
                }
                i = c;
                y = ft_atoi(tr);
                while (y > 0)
                {
                    ft_putchar(' ');
                    y--;
                }
                if (fmt[c] == '.')
                {
                    free(tr);
                    tr = calloc(10, 1);
                    c = i + 1;
                    y = 0;
                    while (fmt[c] != 'i' && fmt[c] != 'd' && fmt[c] != 'x' && fmt[c] != 'X' && fmt[c] != 'u' && fmt[c] != 'p' && fmt[c] != 's')
                    {
                        tr[y] = fmt[c];
                        y++;
                        c++;
                    }
                    i = c;
                    if (fmt[c] == 'i' || fmt[c] == 'd')
                    {
                        int t = 0;
                        c = ft_atoi(tr);
                        int it = va_arg(args, int);
                        int co = digit_count(it, 10);
                        if (it < 0)
                        {
                            ft_putchar('-');
                            it *= -1;
                        }
                        else
                            count--;
                        if (c > 512)
                            c = 512;
                        while (co < c)
                        {
                            ft_putnbr_fd(0, 1);
                            c--;
                            t++;
                        }
                        if (it)
                            ft_putnbr_fd(it, 1);
                        count--;
                        count += c + t - y;
                    }
                    else if (fmt[c] == 's')
                    {
                        c = ft_atoi(tr);
                        char *s = va_arg(args, char *);
                        ft_putnstr(s, c);
                        count--;
                        count -= c;
                    }
                    else if (fmt[c] == 'x' || fmt[c] == 'X')
                    {
                        int t = 0;
                        int x = va_arg(args, int);
                        int co = ft_strlen(ft_to_hexa(x, fmt[i], x));
                        c = ft_atoi(tr);
                        count--;
                        if (c > 512)
                            c = 512;
                        while (co < y)
                        {
                            ft_putnbr_fd(0, 1);
                            c--;
                            t++;
                        }
                        ft_putstr(ft_to_hexa(x, fmt[i], x));
                        count--;
                        count += c + t - y;
                    }
                }
            }
            count--;
        }
        else
            ft_putchar(fmt[i]);
        i++;
        t.i++;
    }
    va_end(args);
    return (count + i);
}
