
#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdint.h>

typedef struct s_flag
{
    int len;
    int i;
    va_list args;
    char *frmt;
    char c;
    int it;
    char *p;
    char *s;
    int x;
    unsigned int u;
    char flage;
    int size;
} t_flag;

void ft_putnbr_fd(int n, int fd);
size_t ft_strlen(const char *s);
int ft_putstr(char const *s);
char *ft_strchr(const char *s, int c);
int print_m(t_flag *t);
void get_flage(char *fmt, t_flag *t);
size_t digit_count(long nb, int base);
int CheckFlags(char *fmt, t_flag *t);
int print_zero(int p);
int zero_w(char *fmt, t_flag *t, int p, int s, int w);
int get_number(char *fmt, int *i, t_flag *t);
void pointer_pre(int w, t_flag *t, int p);
void negative_presicion(char *fmt, t_flag *t);
void presionpoint(char *fmt, t_flag *t);
void print_unsigned(char *fmt, t_flag *t, int w, int p);
int print_space(int p);
char *ft_strdup(const char *str);
void presionpoint_prime(char *fmt, t_flag *t);
void print_intger(char *fmt, t_flag *t, int w, int p);
int ft_putchar(char c);
int print_address_hex(void *p0, int *len, int b, t_flag *t);
int print_p(t_flag *t, void *p);
int print_di(t_flag *t, int it);
int ft_isdigit(int c);
void presion_zero(char *fmt, t_flag *t);
int print_c(t_flag *t, int c);
void printpresi_c(int w, t_flag *t, int c);
void hexa_presition(int w, int p, t_flag *t, char *fmt);
int print_s(t_flag *t, char *s);
int print_u(t_flag *t, unsigned int u);
int zapper_neg(char *fmt, int d);
size_t digit_count(long nb, int base);
char *ft_itoa_base(int value, int base, int c);
int ft_atoi(const char *str);
char *ft_to_hexa(unsigned int num, char c, int i);
int print_hexa(t_flag *t, long x, char cap);
int Checkpresicion(char *fmt, t_flag *t);
//int CheckFlags(char *fmt,t_flag t);

#endif