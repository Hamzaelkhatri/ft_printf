/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:22:33 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/13 11:32:50 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	get_flage(char *fmt, t_flag *t)
{
	int i;

	i = t->i + 1;
	while (fmt[i] && ft_strchr("+ .-*#lh0123456789cspdiuxX%", fmt[i]))
	{
		if (ft_strchr("cspdiuxX%", fmt[i]))
		{
			t->flage = fmt[i];
			break ;
		}
		i++;
	}
}
