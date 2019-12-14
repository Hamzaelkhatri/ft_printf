/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:22:33 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/13 09:34:21 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		print_zero(int p)
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

int		print_space(int p)
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

int		operation(char *str, int i, int l, int sign)
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

int		ft_atoi(char *str)
{
	size_t		i;
	int			sign;
	int			l;
	int			r;

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

void	pre_st(t_flag *t, int w, int p)
{
	if (t->size <= w || t->size <= p)
		ft_pre(p, w, t);
	else
	{
		zero_w(t, -100, -100, -100) == -1
			? ft_putnstr(t->s, p)
			: ft_putnstr(t->s, t->size);
		zero_w(t, -100, -100, -100) == -1
			? print_space(w - p)
			: print_space(w - t->size);
		t->len += t->size;
	}
}
