/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presicion_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:08:51 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/12 21:35:18 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		print_unsigned_td(int p, int w, t_flag *t)
{
	int ts;
	int y;

	if (p >= w)
	{
		ts = print_zero((p > t->size ? p - t->size : t->size));
		(t->u == 0 && p == 0)
			? zero_w(t, p, t->u, w)
			: print_u(t, t->u);
		t->len += (t->size > p ? 0
				: p - t->size) + (t->u == 0 && p == 0 ? 1 : 0);
	}
	else
	{
		y = (p > t->size ? p : t->size);
		ts = print_space(w > t->size ? w - y :
				t->size);
		ts = print_zero(p - t->size) + ((t->u == 0 && p == 0) ?
				zero_w(t, p, t->u, w)
				: print_u(t, t->u));
		t->len += (t->size > w ? 0 : w - t->size)
			+ (t->u == 0 ? 1 : 0);
	}
}

static void		print_un_neg(t_flag *t, int p, int w)
{
	int ts;

	if (p >= w)
	{
		ts = print_zero(p - t->size) + ((t->u == 0 && p == 0)
				? zero_w(t, p, t->u, w) : print_u(t, t->u));
		t->len += (t->size > p ? 0 : p - t->size);
	}
	else
	{
		print_zero(p - t->size);
		(t->u == 0 && p == 0) ? zero_w(t, p, t->u, w)
			: print_u(t, t->u);
		ts = p > t->size ? p : t->size;
		print_space(w > t->size ? w - ts : t->size);
		t->len += (t->size > w ? 0 : w - t->size);
	}
}

void			print_unsigned(t_flag *t, int w, int p)
{
	int ts;

	ts = 0;
	if (w >= 0)
	{
		if (t->size < w || t->size < p)
			print_unsigned_td(p, w, t);
		else
			(t->u == 0 && p == 0) ?
				zero_w(t, p, t->u, w)
				: print_u(t, t->u);
	}
	else
	{
		w *= -1;
		if (t->size < w || t->size < p)
			print_un_neg(t, p, w);
		else
			(t->u == 0 && p == 0) ? zero_w(t, p, t->u, w)
				: print_u(t, t->u);
	}
}

int				zero_w(t_flag *t, int p, int s, int w)
{
	int i;

	i = t->i + 1;
	while (t->frmt[i])
	{
		if (ft_strchr(".", t->frmt[i]))
		{
			i = -1;
			break ;
		}
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

int				print_hexa(t_flag *t, long x, char cap)
{
	t->len += ft_strlen(ft_to_hexa(x, cap, x));
	ft_putstr(ft_to_hexa(x, cap, x));
	t->i++;
	return (t->len);
}
