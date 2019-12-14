/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presion_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:22:33 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/13 13:51:19 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		pointer_sup(t_flag *t, int w, int p)
{
	if (t->size < w || t->size < p)
	{
		if (p >= w)
		{
			t->len += ft_putstr("0x");
			t->len += print_zero(p - t->size + 2);
			t->len += print_address_hex(t->p, &t->len, 2) - t->size - 1;
		}
		else
			t->len += print_space((p > 0) ? (w - p - 3) : w - t->size) -
				t->size - 1 + ft_putstr("0x") + print_zero(p - t->size + 2) +
				print_address_hex(t->p, &t->len, 2) + 1;
	}
	else
	{
		t->len += ft_putstr("0x");
		if (t->p != 0 && p == 0)
			print_address_hex(t->p, &t->len, 2);
		else
			t->len += 2;
	}
}

void		pointer_pre(int w, t_flag *t, int p)
{
	if (w >= 0)
		pointer_sup(t, w, p);
	else
	{
		w *= -1;
		if (t->size < w || t->size < p)
		{
			ft_putstr("0x");
			if (p >= w)
				t->len += print_zero(p - t->size + 2) +
					print_address_hex(t->p, &t->len, 2) - t->size - 1;
			else
				t->len += print_zero(p - t->size + 2) +
					print_address_hex(t->p, &t->len, 2) +
					print_space((p > 0) ? (w - p - 2)
							: w - t->size) -
					t->size - 1;
		}
		else
		{
			ft_putstr("0x");
			print_address_hex(t->p, &t->len, 2);
		}
	}
}

void		hexa_pre(t_flag *t, int w, int p)
{
	int ts;

	ts = 0;
	if (t->size < w || t->size < p)
	{
		if (p >= w)
		{
			ts += print_zero(p - t->size) + ((t->x == 0 && p == 0)
					? zero_w(t, p, t->x, w)
					: print_hexa(t, t->x, t->flage)) -
				t->size - 1;
			t->len += (p > t->size ? p - t->size : t->size);
		}
		else
		{
			ts = print_space(check_space(w, p, t)) + print_zero(p - t->size)
				+ ((t->x == 0 && p == 0) ? zero_w(t, p, t->x, w)
				: print_hexa(t, t->x, t->flage) - t->size - 1);
			t->len += (w > t->size ? w - t->size : t->size);
		}
	}
	else
		(t->x == 0 && p == 0) ? zero_w(t, p, t->x, w)
			: print_hexa(t, t->x, t->flage);
}

void		hexa_pre_pre(int p, int w, t_flag *t)
{
	int ts;

	ts = 0;
	if (p >= w)
	{
		ts += print_zero(p - t->size) + ((t->x == 0 && p == 0)
				? zero_w(t, p, t->x, w)
				: print_hexa(t, t->x, t->flage)) -
			t->size - 1;
		t->len += (p > t->size ? p - t->size : t->size);
	}
	else
	{
		ts += print_zero(p - t->size) + ((t->x == 0 && p == 0)
				? zero_w(t, p, t->x, w)
				: print_hexa(t, t->x, t->flage)) +
			print_space(check_space(w, p, t)) - t->size - 1;
		t->len += (w > t->size ? w - t->size : t->size);
	}
}

void		hexa_presition(int w, int p, t_flag *t)
{
	int ts;

	ts = 0;
	if (w >= 0)
	{
		hexa_pre(t, w, p);
	}
	else
	{
		w *= -1;
		if (t->size < w || t->size < p)
		{
			hexa_pre_pre(p, w, t);
		}
		else
			(t->x == 0 && p == 0) ? zero_w(t, p, t->x, w)
				: print_hexa(t, t->x, t->flage);
	}
}
