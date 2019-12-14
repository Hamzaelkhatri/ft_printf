/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <helkhatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:08:51 by helkhatr          #+#    #+#             */
/*   Updated: 2019/12/13 04:27:29 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		*ft_calloc(unsigned int nitems, unsigned int size)
{
	int		i;
	char	*d;
	int		k;

	k = 0;
	i = 0;
	d = (char *)malloc(size * nitems);
	if (d == NULL)
	{
		return (NULL);
	}
	i = size * nitems;
	while (i > k)
	{
		d[k] = '\0';
		k++;
	}
	return (d);
}

char		*ft_strdup(const char *str)
{
	size_t	lenght;
	char	*cpy;

	lenght = ft_strlen(str);
	cpy = (char *)malloc(sizeof(char) * (lenght + 1));
	if (cpy == NULL)
		return (NULL);
	lenght = 0;
	while (str[lenght])
	{
		cpy[lenght] = str[lenght];
		lenght++;
	}
	cpy[lenght] = '\0';
	return (cpy);
}

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*(s + i) != 0)
	{
		i++;
	}
	return (i);
}

int			ft_putstr(char const *s)
{
	int l;

	if (s)
	{
		l = ft_strlen(s);
		write(1, (const void *)s, l);
	}
	return (0);
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int nb;

	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	else
		nb = n;
	if (nb / 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb % 10 + '0');
}
