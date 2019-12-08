/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:22:33 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/04 07:35:37 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void get_flage(char *fmt, t_flag *t)
{
    int i;
    i = t->i + 1;
    while (fmt[i])
    {
        if (ft_strchr("cspdiuxX%%", fmt[i]))
        {
            t->flage = fmt[i];
            break;
        }
        i++;
    }
}