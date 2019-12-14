/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presionpoint_tw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:22:33 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/13 13:52:22 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putnstr(char const *s, int i)
{
	char c;

	if (!s)
	{
		s = ft_strdup("(null)");
	}
	while (*s != '\0' && 0 < i)
	{
		c = *s;
		write(1, (const void *)&c, 1);
		s++;
		i--;
	}
}

void	presionpoint(char *fmt, t_flag *t)
{
	int i;
	int w;
	int p;

	i = t->i + 1;
	w = 0;
	p = 0;
	if (fmt[i + 1] == '-')
		i += zapper_neg(&fmt[i], 1);
	if (t->flage == 'd' || t->flage == 'i')
	{
		w = get_number(fmt, &i, t);
		p = get_number(fmt, &i, t);
		t->it = va_arg(t->args, int);
		t->size = digit_count(t->it, 10);
		print_intger(t, w, p);
		t->i = i;
	}
	else
	{
		presition_p_td(t, fmt, w, p);
	}
}

void	presionpoint_trime(char *fmt, t_flag *t)
{
	int i;
	int w;
	int p;

	i = t->i + 1;
	if (t->flage == 's')
	{
		w = get_number(fmt, &i, t);
		p = get_number(fmt, &i, t);
		t->s = va_arg(t->args, char *);
		t->size = (!t->s ? 6 : ft_strlen(t->s));
		presicion_str(t, w, p);
		t->i = i;
	}
}

void	ft_pre_tw(t_flag *t, int w, int p)
{
	zero_w(t, -100, -100, -100) == -1 ? print_space(w - p)
		: print_space(w - t->size);
	zero_w(t, -100, -100, -100) == -1 ? ft_putnstr(t->s, p)
		: ft_putnstr(t->s, t->size);
	if (zero_w(t, -100, -100, -100) == -1)
		t->len += w;
	else
		t->len += t->size;
}
