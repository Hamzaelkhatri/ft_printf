/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 20:18:35 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/11 05:24:18 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			digit_count(long nb, int base)
{
	size_t i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	if (nb == 0)
		i = 1;
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char			hex_digit(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}

int				print_address_hex(void *p0, int *len, int b, t_flag *t)
{
	int			i;
	char		*tmp;
	int			c;
	uintptr_t	p;

	p = (uintptr_t)p0;
	c = 0;
	i = 60;
	(b == 0) ? ft_putstr("0x") : 0;
	(p == 0 && b != 5) ? ft_putchar('0') : 0;
	if ((tmp = ft_calloc(20, 1)) == NULL)
		return (0);
	while (i >= 0)
	{
		tmp[c] = hex_digit((p >> i) & 0xf);
		i -= 4;
		c++;
	}
	c = 0;
	while (tmp[c] == '0')
		c++;
	tmp = &tmp[c];
	(b == 0 || b == 2) ? ft_putstr(tmp) : 0;
	*len += digit_count(p, 16) + 2;
	return (*len);
}

int				print_di(t_flag *t, int it)
{
	int l;

	l = t->len;
	t->len += digit_count(it, 10);
	ft_putnbr_fd(it, 1);
	t->i += 1;
	return ((t->len - 1) - l);
}

int				print_p(t_flag *t, void *p)
{
	int l;

	l = t->len;
	print_address_hex(p, &t->len, 0, t);
	t->i++;
	return (t->len - l);
}
