/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csmu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:08:51 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/12 21:35:18 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		print_c(t_flag *t, int c)
{
	ft_putchar(c);
	t->i++;
	t->flage = 'c';
	t->len += 1;
	return (t->len - 2);
}

int		print_s(t_flag *t, char *s)
{
	if (!s)
	{
		ft_putstr("(null)");
		t->len += 6;
	}
	else
	{
		t->len += ft_strlen(s);
		ft_putstr(s);
	}
	t->i++;
	return (t->len);
}

int		print_m(t_flag *t)
{
	ft_putchar('%');
	t->len++;
	t->i++;
	t->flage = '%';
	return (1);
}

void	print_un(unsigned int u)
{
	if (u / 10)
	{
		print_un(u / 10);
		ft_putchar(u % 10 + '0');
	}
	else
		ft_putchar(u % 10 + '0');
}

int		print_u(t_flag *t, unsigned int u)
{
	t->len += digit_count(u, 10);
	print_un(u);
	t->i++;
	return (t->len);
}
