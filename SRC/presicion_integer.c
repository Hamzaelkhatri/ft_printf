/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presicion_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:22:33 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/12 21:35:18 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	intp(int p, t_flag *t, int w, int y)
{
	int m;
	int ts;

	m = 0;
	ts = 0;
	m = (y >= 0 ? 0 : -1);
	ts = p > t->size ? p - m : t->size;
	print_space(w > t->size ? w - ts : t->size);
	m = (p > t->size ? p - t->size : p - w);
	print_neg(&t->it);
	print_zero(m + (y >= 0 ? 0 : 1));
	(t->it == 0 && p == 0) ?
		zero_w(t, p, t->it, w) : print_di(t, t->it);
	ts = (y >= 0 ? 0 : 2);
	t->len += (w > t->size ? w - t->size : 0) + ts;
}

void	int_p(int p, int w, t_flag *t, int y)
{
	int m;
	int ts;

	m = 0;
	ts = 0;
	if (p > w)
	{
		m = (y >= 0 ? 0 : 1);
		ts = print_neg(&t->it);
		print_zero((p > t->size ? p - t->size : 0) + m);
		(t->it == 0 && p == 0) ? zero_w(t, p, t->it, w)
			: print_di(t, t->it);
		ts = (y >= 0 ? 0 : 2);
		t->len += (p > t->size ? p - t->size : 0) + ts;
	}
	else
	{
		intp(p, t, w, y);
	}
}

void	print_neg_int(t_flag *t, int y, int w, int p)
{
	int ts;
	int m;

	m = 0;
	ts = 0;
	print_neg(&t->it);
	ts = (y >= 0 ? 0 : 1);
	print_zero((p > t->size
				? p - t->size : p - w) + ts);
	(t->it == 0 && p == 0) ?
		zero_w(t, p, t->it, w)
		: print_di(t, t->it);
	ts = (y >= 0 ? 0 : -1);
	m = (p > t->size ? p - ts : t->size);
	print_space(w > t->size ? w - m : t->size);
	ts = (y >= 0 ? 0 : 1);
	t->len += (w > t->size ? w - t->size : 0) + ts;
}

void	print_neg_pre(t_flag *t, int y, int w, int p)
{
	int ts;
	int m;

	m = 0;
	ts = 0;
	if (p > w)
	{
		print_neg(&t->it);
		ts = (y >= 0 ? 0 : 1);
		print_zero((p > t->size ? p - t->size : 0) + ts);
		(t->it == 0 && p == 0) ?
			zero_w(t, p, t->it, w) : print_di(t, t->it);
		(t->it == 0 && p == 0)
			? zero_w(t, p, t->it, w) : 0;
		ts = (y >= 0 ? 0 : 2);
		t->len += (p > t->size ? p - t->size : 0) + ts;
	}
	else
		print_neg_int(t, y, w, p);
}

void	print_intger(t_flag *t, int w, int p)
{
	int y;

	y = t->it;
	if (w >= 0)
	{
		if (t->size < w || t->size < p)
			int_p(p, w, t, y);
		else
			(t->it == 0 && p == 0)
				? zero_w(t, p, t->it, w) : print_di(t, t->it);
	}
	else
	{
		w *= -1;
		if (t->size < w || t->size < p)
			print_neg_pre(t, y, w, p);
		else
		{
			(t->it == 0 && p == 0)
				? zero_w(t, p, t->it, w)
				: print_di(t, t->it);
		}
	}
}
