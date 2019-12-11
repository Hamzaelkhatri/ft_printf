/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presicion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:22:33 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/11 04:40:07 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_n(char *fmt, int c, int *i)
{
	char	nbr[20];
	int		j;

	j = 0;
	nbr[0] = '0';
	while (fmt[c] != '.' && fmt[c] != '\0' && !ft_strchr("cspdiuxX%%", fmt[c]))
	{
		nbr[j] = fmt[c];
		c++;
		j++;
	}
	if (fmt[c] == '.')
		c++;
	*i = c;
	return (ft_atoi(nbr));
}

int		get_number(char *fmt, int *i, t_flag *t)
{
	int o;
	int c;

	o = 1;
	c = *i;
	while (!ft_strchr("cspdiuxX%%", fmt[c]))
	{
		if (fmt[c] == '-')
			o = -1;
		if (ft_strchr("*", fmt[c]))
		{
			*i = c + 1;
			return (o * va_arg(t->args, int));
		}
		c++;
	}
	c = *i;
	return (get_n(fmt, c, i));
}

int		checkneg(char *fmt, t_flag *t)
{
	int i;

	i = t->i;
	while (!ft_strchr("cspdiuxX%%", fmt[i]))
	{
		if (ft_strchr(".", fmt[i]))
			return (0);
	}
	return (1);
}

int		checkpresicion(char *fmt, t_flag *t)
{
	int		i;
	char	*tr;

	i = t->i + 1;
	i = t->i + 1;
	i = t->i;
	if (fmt[i + 1] == '0')
	{
		presion_zero(fmt, t);
	}
	else
		presionpoint(fmt, t);
	return (0);
}
