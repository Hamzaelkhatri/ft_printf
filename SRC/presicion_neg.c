/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presicion_neg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:22:33 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/13 06:07:17 by helkhatr         ###   ########.fr       */
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
