/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presionpoint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 11:21:07 by osamoile          #+#    #+#             */
/*   Updated: 2019/12/13 13:52:22 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_pre(int p, int w, t_flag *t)
{
	int y;

	if (p > w)
	{
		ft_putnstr(t->s, p);
		print_space(w - t->size);
		t->len += (w > t->size ? w : t->size);
	}
	else
	{
		y = (p > t->size) ? w - t->size : w - p;
		zero_w(t, -100, -100, -100) == -1
			? ft_putnstr(t->s, p)
			: ft_putnstr(t->s, t->size);
		zero_w(t, -100, -100, -100) == -1
			? print_space(y)
			: print_space(w - t->size);
		t->len += w;
	}
}

void	ft_pre_str(int p, int w, t_flag *t)
{
	if (p > w)
	{
		print_space(w - t->size);
		ft_putnstr(t->s, p);
		t->len += (w > t->size ? w : t->size);
	}
	else
	{
		if (zero_w(t, -100, -100, -100) == -1)
			print_space((p > t->size) ? w - t->size : w - p);
		else
			print_space(w - t->size);
		if (zero_w(t, -100, -100, -100) == -1)
			ft_putnstr(t->s, p);
		else
			ft_putnstr(t->s, t->size);
		t->len += w;
	}
}

void	presicion_str(t_flag *t, int w, int p)
{
	int ts;

	ts = 0;
	if (w >= 0)
	{
		if (t->size <= w || t->size <= p)
			ft_pre_str(p, w, t);
		else
			ft_pre_tw(t, w, p);
	}
	else
	{
		w *= -1;
		pre_st(t, w, p);
	}
}

void	presionpoint_prime(char *fmt, t_flag *t)
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

void	presition_p_td(t_flag *t, char *fmt, int w, int p)
{
	int i;

	i = t->i + 1;
	if (t->flage == 'c' || t->flage == '%')
	{
		w = get_number(fmt, &i, t);
		get_number(fmt, &i, t);
		(t->flage == 'c')
			? printpresi_c(w, t, va_arg(t->args, int))
			: printpresi_c(w, t, '%');
		t->i = i;
	}
	else if (t->flage == 'u')
	{
		w = get_number(fmt, &i, t);
		p = get_number(fmt, &i, t);
		t->u = va_arg(t->args, unsigned int);
		t->size = digit_count(t->u, 10);
		print_unsigned(t, w, p);
		t->i = i;
	}
	else
		presionpoint_prime(fmt, t);
}
