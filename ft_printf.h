/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 22:35:38 by helkhatr          #+#    #+#             */
/*   Updated: 2019/11/22 22:35:38 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct s_printf
{
    char c;
    int  i;
    char *s;
    void *p;
    int x;
    unsigned u;
}s_printf;


#endif