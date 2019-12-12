/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presicion_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:22:33 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/12 21:35:18 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void			zero_c(t_flag *t, char *fmt)
{
	int i;
	int w;

	if (t->flage == 'c' || t->flage == '%')
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
}

void			zero_x(t_flag *t, char *fmt)
{
	int i;
	int w;

	if (t->flage == 'x' || t->flage == 'X')
	{
		i = t->i + 1;
		w = get_number(fmt, &i, t);
		t->x = va_arg(t->args, long);
		t->size = ft_strlen(ft_to_hexa(t->x, t->flage, t->x));
		print_zero((w > t->size) ? w - t->size : 0);
		ft_putstr(ft_to_hexa(t->x, t->flage, t->x));
		t->len += (w > t->size) ? w : t->size;
		t->i = i;
	}
	else
		zero_c(t, fmt);
}

void			zero_p(t_flag *t, char *fmt)
{
	int i;
	int w;

	i = t->i + 1;
	w = get_number(fmt, &i, t);
	t->size = digit_count((uintptr_t)t->p, 16) + 2;
	t->p = va_arg(t->args, void *);
	ft_putstr("0x");
	print_zero(w - t->size);
	print_address_hex(t->p, &t->len, 2);
	t->i = i;
}

void			presicion_zer_tw(t_flag *t, char *fmt)
{
	int i;
	int w;

	if (t->flage == 's')
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
		zero_p(t, fmt);
	else
		zero_x(t, fmt);
}

void			zero_d_u(char *fmt, t_flag *t)
{
	int i;
	int w;
	int d;
	int m;

	i = t->i + 1;
	d = 0;
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
	m = (d < 0 ? 2 : 0);
	t->len += (w > t->size) ?
		w - t->size + m : 0;
	(t->flage == 'u') ? print_u(t, t->u) : print_di(t, t->it);
	t->i = i;
}
