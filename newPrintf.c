/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newPrintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:22:33 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/09 17:27:07 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(char c)
{
    write(1, (const void *)&c, 1);
    return (1);
}

int ft_printf(const char *fmt, ...)
{
    t_flag t;
    t.flage = ' ';
    t.i = 0;
    t.size = 0;
    t.len = 0;
    va_start(t.args, fmt);
    while (fmt[t.i] != '\0')
    {
        if (fmt[t.i] == '%')
            CheckFlags((char *)fmt, &t);
        else
        {
            ft_putchar(fmt[t.i]);
            t.len++;
        }
        t.i++;
    }
    return (t.len);
}

// int main(void)
// {
//     void *d = malloc(110);
//     //int c = ft_printf("\n{%s} {%d} {%c} {%p}", "hello", 3, 'c', d);
//     // printf("\nle nobre de caracter est  |%i|\n", c);
//     // int c = ft_printf("\n{%----------*d}", 4, 4);
//     //int t = printf("\n{%s} {%d} {%c} {%p}", "hello", 3, 'c', d);
//     // int t = printf("\n{%----------*d}", 4, 4);
//     // printf("\n|%i| |%i|\n", t, c);
//     //int j = ft_printf("[%400.50p]\n", 0);
//     //int c = ft_printf("%30d\n", 0);  //
//     //int e = ft_printf("%07d\n", -54); //{return test("%8.3x", 8375);}
//     int j = ft_printf("%-7.5s\n", "yolo");
//     int e = printf("%-7.5s\n", "yolo");
//     printf("\n[%i][%i]", e, j);
//     return (0);
// }