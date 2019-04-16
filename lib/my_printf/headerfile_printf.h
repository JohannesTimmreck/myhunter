/*
** EPITECH PROJECT, 2018
** header_file
** File description:
** header_for_myprintf
*/

#ifndef Position
#define Position
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

typedef void (*fct_ptr)(va_list list);
typedef void (*left_ptr)(va_list list, int nbr, char fill);
typedef void (*right_ptr)(va_list list, int nbr);

int my_printf(char const *src, ...);

void my_rightstr(va_list list, int nbr);
void my_rightchar(va_list list, int nbr);
void my_right_nbr(va_list list, int len);
void right_print_nbr(int to_divide_by, int nb, int len);
void my_right_nbr_oct(va_list list, int len);
void my_right_nbr_dec(va_list list, int len);
void my_right_nbr_hexdcl(va_list list, int len);
void my_right_nbr_hexdcu(va_list list, int len);
void my_right_nbr_bin(va_list list, int len);
void my_rightstr_mod(va_list list, int len);
void my_leftchar(va_list list, int len, char fill);
void my_left_nbr(va_list list, int len, char fill);
void my_left_nbr_dec(va_list list, int len, char fill);
void my_left_nbr_hexdcl(va_list list, int len, char fill);
void my_left_nbr_hexdcu(va_list list, int len, char fill);
void my_left_nbr_oct(va_list list, int len, char fill);
void my_left_nbr_bin(va_list list, int len, char fill);
void my_leftstr(va_list list, int len, char fill);
void my_leftstr_mod(va_list list, int len, char fill);
void left_print_nbr_oct(int to_divide_by, unsigned int nb, int len, char fill);
void my_left_nbr_oct_mod(unsigned int nb, int len, char fill);
int my_getfnbr(char const *str, int *count);
int my_strlen(char *str);
void my_putchar(char c);
void my_putfchar(va_list list);
void my_put_nbr(va_list list);
void my_putstr(va_list list);
void my_put_nbr_oct(va_list list);
void my_put_nbr_dec(va_list list);
void my_putperc(va_list list);
void my_put_nbr_hexdcl(va_list list);
void my_put_nbr_hexdcu(va_list list);
void my_put_nbr_bin(va_list list);
void my_putstr_mod(va_list list);
int right_calc_tens(int temp);
int calc_tens(int temp);
int calc_digits(unsigned int temp, int base);
int calc_udigits(unsigned int temp, int base);

#endif
