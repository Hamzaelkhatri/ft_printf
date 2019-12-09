#include <stdio.h>
#include <stdlib.h>

size_t ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (*(s + i) != 0)
    {
        i++;
    }
    return (i);
}

int ft_putstr(char const *s)
{
    int l;

    if (s)
    {
        l = ft_strlen(s);
        write(1, (const void *)s, l);
    }
    return (0);
}

void ft_putnbr_fd(int n, int fd)
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

void printf_flag(const char *flag, int *i)
{
    int j = *i + 1;
    while (flag[j] != 'i' && flag[j] != 'd' && flag[j] != 'x' && flag[j] != 'X' && flag[j] != 'u' && flag[j] != 'p')
    {
        ft_putchar(flag[j]);
        j++;
    }
    *i = j - 1;
}

int ft_toupper(int c)
{
    if ((c >= 'a' && c <= 'z'))
        return (c - 32);
    else
        return (c);
}

void print_presicion()
{
}

char *ftstrclr(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        str[i] = '\0';
        i++;
    }
    return (0);
}

char *ft_strdup(const char *str)
{
    size_t lenght;
    char *cpy;

    lenght = ft_strlen(str);
    cpy = (char *)malloc(sizeof(char) * (lenght + 1));
    if (cpy == NULL)
    {
        return (NULL);
    }
    lenght = 0;
    while (str[lenght])
    {
        cpy[lenght] = str[lenght];
        lenght++;
    }
    cpy[lenght] = '\0';
    return (cpy);
}