/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:08:51 by helkhatr          #+#    #+#             */
/*   Updated: 2019/11/22 17:08:51 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
 
size_t			ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*(s + i) != 0)
	{
		i++;
	}
	return (i);
}



void			ft_putchar(char c)
{
	write(1, (const void *)&c, 1);
}

void	ft_putstr(char const *s)
{
	int l;

	if (s)
	{
		l = ft_strlen(s);
		write(1, (const void *)s, l);
	}
}

void	ft_putnbr_fd(int n, int fd)
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

void	print_u(unsigned int n)
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
		print_u(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb % 10 + '0');
}

char hex_digit(int v) 
{
    if (v >= 0 && v < 10)
        return '0' + v;
    else
        return 'A' + v - 10;
}

void print_address_hex(void* p0) 
{
    int i;
    uintptr_t p = (uintptr_t)p0;
    i = (sizeof(p) << 3) - 4;
    while (i>=0) 
    {
        ft_putchar(hex_digit((p >> i) & 0xf));
         i -= 4;
    }
}

static size_t	digit_count(long nb, int base)
{
	size_t		i;

	i = 0;
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(int value, int base, int c)
{
	char	*ret;
	char	*tab_base;
	int		taille;
	int		i;
	int		sign;

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
    if(c == 'X')
	    tab_base = "0123456789ABCDEF";
    else
        tab_base = "0123456789abcdef"; 
	taille = digit_count(value, base);
	taille += (sign ? 1 : 0);
	ret = (char *)malloc(sizeof(char) * (taille + 1));
	i = 1;
	sign ? (ret[0] = '-') : 0;
	while (value != 0)
	{
		ret[taille - i++] = tab_base[value % base];
		value /= base;
	}
	ret[taille] = '\0';
    free(tab_base);
	return (ret);
}

void printf_flag(const char *flag,int *i)
{
    int j = *i + 1;
        while (flag[j] != 'i' && flag[j] != 'd' && flag[j] != 'x' && flag[j] != 'X' && flag[j] != 'u' && flag[j] != 'p')
        {
            ft_putchar(flag[j]);
            j++;
        }
    *i = j - 1;
}

int		ft_toupper(int c)
{
	if ((c >= 'a' && c <= 'z'))
		return (c - 32);
	else
		return (c);
}


int simple_printf(const char* fmt, ...)
{
    int i;
    i = 0;
    int count = 0;
    va_list args;
    va_start(args, fmt);
 
    while (fmt[i] != '\0') 
    {
        if(fmt[i] == '%')
        {
            if (fmt[i+1] == 'd' | fmt[i+1] == 'i') 
            {
                int it = va_arg(args, int);
                count += digit_count(it,10);
                ft_putnbr_fd(it,1);
                count --;
                i++;
            }
            else if (fmt[i+1] == 'c') 
            {
                int c = va_arg(args, int);
                count += 1;
                ft_putchar(c);
                count --;
                i++;
            } 
            else if (fmt[i+1] == 's') 
            {
                 char *s = va_arg(args, char *);
                 count+=ft_strlen(s);
                 ft_putstr(s);
                 count --;
                 i++;
            }
            else if(fmt[i+1] == '%')
            {
                ft_putchar('%');
                i++;
            }
            else if(fmt[i+1]=='p')
            {
                void *p = va_arg(args, void *);
                print_address_hex(p);
                i++;
            }
            else if(fmt[i+1]=='x' | fmt[i+1]=='X')
            {
                int x =  va_arg(args,int);
                count += ft_strlen(ft_itoa_base(x,16,fmt[i+1]));
                ft_putstr(ft_itoa_base(x,16,fmt[i+1]));
                count--;
                i++;
            }
            else if(fmt[i+1]=='u')
            {
                unsigned int u = va_arg(args,unsigned int);
                count +=digit_count(u,10);
                print_u(u);
                count--;
                i++;
            }
            else if(fmt[i+1]==39)
            {
                printf_flag(fmt,&i);
            }
            count --;
        }
        else
            ft_putchar(fmt[i]);
        i++;
    }
    va_end(args);
    return(count + i);
}
 
int main(void)
{
  int c = simple_printf("123456789%X\n",0x3F);
  int d = printf("123456789%X\n",0x3F);
  printf("%i\n%d",c,d);
}