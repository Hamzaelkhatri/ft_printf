/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presicion_neg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:22:33 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/12 21:35:18 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	if (c == 0)
		return ((char *)(s + i));
	return (NULL);
}

int		zapper_neg(char *fmt, int d)
{
	int i;

	i = 0;
	while (fmt[i] == '-')
	{
		i++;
	}
	if (d == 1)
		i--;
	return (i);
}

void	negative_presicion_tw(t_flag *t, int y, char *fmt, char *tr)
{
	int g;

	g = 0;
	if (y == 0)
		y = ft_atoi(tr);
	g = y - checkflags(fmt, t);
	g--;
	print_space(g);
	t->len += g;
}

void	negative_presicion(char *fmt, t_flag *t)
{
	int		i;
	char	*tr;
	int		c;
	int		y;

	i = t->i + 2;
	c = -1;
	y = 0;
	tr = calloc(20, sizeof(char));
	i += zapper_neg(&fmt[i], 0);
	while (ft_strchr("cspdiuxX%%", fmt[i]) == NULL)
	{
		if (!ft_strchr("*", fmt[i]))
			tr[++c] = fmt[i];
		else
		{
			y = va_arg(t->args, int);
			break ;
		}
		i++;
	}
	t->i = i - 1;
	negative_presicion_tw(t, y, fmt, tr);
}

void	printpresi_c(int w, t_flag *t, int c)
{
	if (w > 1)
	{
		print_space(w - 1);
		print_c(t, c);
		t->len += w - 1;
	}
	else if (w < 0)
	{
		w *= -1;
		print_c(t, c);
		print_space(w - 1);
		t->len += w - 1;
	}
	else
		print_c(t, c);
}
