/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 04:43:53 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/11 04:45:43 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static size_t digit_count(long nb, int base)
{
	size_t i;

	i = 0;
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

void ft_it_base(int sign, char ret, char *tab_base, int base)
{
	sign ? (ret[0] = '-') : 0;
	while (value != 0)
	{
		ret[taille - i++] = tab_base[value % base];
		value /= base;
	}
	ret[taille] = '\0';
}

char *ft_itoa_base(int value, int base)
{
	char *ret;
	char *tab_base;
	int taille;
	int i;
	int sign;

	if (base < 2 || base > 16)
		return (0);
	if (base == 10 && value == -2147483648)
		return ("-2147483648");
	sign = 0;
	if (base == 10 && value < 0)
		sign = 1;
	if (value < 0)
		value = -value;
	if (value == 0)
		return ("0");
	tab_base = (char *)malloc(sizeof(char) * 17);
	tab_base = "0123456789ABCDEF";
	taille = digit_count(value, base);
	taille += (sign ? 1 : 0);
	ret = (char *)malloc(sizeof(char) * (taille + 1));
	i = 1;
	return (ret);
}

int main(int ac, const char **av)
{
	if (ac == 3)
	{
		printf("taille de value : %i\n", digit_count(atoi(av[1]), atoi(av[2])));
		printf("itoa : %s\n", ft_itoa_base(atoi(av[1]), atoi(av[2])));
	}
	return (0);
}
