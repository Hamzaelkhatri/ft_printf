/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presicion_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:08:51 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/12 21:35:18 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_itoa_base(int value, int base, int c)
{
	char	*ret;
	char	*tab_base;
	int		taille;
	int		i;

	if (value < 0)
		value = -value;
	if (value == 0)
		return ("0");
	tab_base = (char *)malloc(sizeof(char) * 17);
	if (c == 'X')
		tab_base = "0123456789ABCDEF";
	else
		tab_base = "0123456789abcdef";
	taille = digit_count(value, base);
	ret = calloc(taille, 1);
	i = 1;
	while (value != 0)
	{
		ret[taille - i++] = tab_base[value % base];
		value /= base;
	}
	return (ret);
}

char	*ft_to_hexa(unsigned int num, char c, int i)
{
	unsigned int	num1;
	int				cnt;
	char			*str;

	i > 0 ? ft_itoa_base(i, 16, c) : 0;
	num1 = num;
	cnt = 1;
	while (num1 > 15)
	{
		num1 /= 16;
		cnt++;
	}
	str = (char *)malloc(sizeof(char) * (cnt + 1));
	str[cnt--] = '\0';
	while (cnt >= 0)
	{
		if ((num % 16) >= 10 && c == 'x')
			str[cnt--] = ((num % 16) % 10) + 'a';
		else if ((num % 16) >= 10 && c == 'X')
			str[cnt--] = ((num % 16) % 10) + 'A';
		else
			str[cnt--] = (num % 16) + '0';
		num /= 16;
	}
	return (str);
}
