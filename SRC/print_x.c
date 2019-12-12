/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:08:51 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/12 21:35:18 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		searchprecision(char *fmt, t_flag *t)
{
	int i;

	i = t->i + 1;
	while (fmt[i] == '0')
	{
		i++;
	}
	while (!ft_strchr("dipxX%%", fmt[i]))
	{
		if (ft_strchr(".-", fmt[i]))
		{
			(fmt[i] == '-' && fmt[i - 1] == '0') ? t->i = i - 1 : 0;
			presionpoint(fmt, t);
			return (1);
		}
		i++;
	}
	return (0);
}

void	negative_val(int *it, t_flag *t)
{
	if (*it < 0)
	{
		*it *= -1;
		t->size += 1;
		ft_putchar('-');
	}
}

int		print_neg(int *it)
{
	if (*it < 0)
	{
		ft_putchar('-');
		*it *= -1;
		return (0);
	}
	return (0);
}

int		print_tr(int u, int p, int w, int size)
{
	int y;
	int l;
	int s;

	y = 0;
	l = 0;
	if (p >= 0)
	{
		y = (u >= 0 ? w - p : w - p - 1);
		l = (u < 0 ? 0 : 1);
		s = (w > p ? 0 : 1);
		return (print_space((size > p ? w - size - 1 : w - p - s)));
	}
	else
	{
		l = (u <= 0 ? 0 : 1);
		return (print_space(0));
	}
}
