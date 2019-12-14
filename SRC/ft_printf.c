/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:22:33 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/13 04:37:57 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_putchar(char c)
{
	write(1, (const void *)&c, 1);
	return (1);
}

int		ft_printf(const char *fmt, ...)
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
		{
			checkflags((char *)fmt, &t);
		}
		else
		{
			ft_putchar(fmt[t.i]);
			t.len++;
		}
		t.i++;
	}
	return (t.len);
}
