/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:22:33 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/08 09:38:02 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_zero(int p)
{
    int i;
    i = 0;
    while (p > 0)
    {
        ft_putchar('0');
        p--;
        i++;
    }
    return (i);
}

int print_space(int p)
{
    int i;
    i = 0;
    while (p > 0)
    {
        ft_putchar(' ');
        i++;
        p--;
    }
    return (i);
}

int operation(const char *str, int i, int l, int sign)
{
    int r;

    r = 0;
    while (str[i] != '\0' && str[i] <= 57 && str[i] >= 48)
    {
        r = r * 10 + str[i] - '0';
        i++;
        l++;
    }
    if (l > 19)
    {
        if (sign == 1)
            return (-1);
        else
            return (0);
    }
    return (sign * r);
}

int ft_atoi(const char *str)
{
    size_t i;
    int sign;
    int l;
    int r;

    i = 0;
    sign = 1;
    l = 0;
    r = 0;
    while (str[i] == '\n' || str[i] == '\v' || str[i] == '\t' ||
           str[i] == '\r' || str[i] == ' ' || str[i] == '\f')
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    return (operation(str, i, l, sign));
}