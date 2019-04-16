/*
** EPITECH PROJECT, 2018
** put hexadec nbr
** File description:
** my_printf
*/


#include "../headerfile_printf.h"

void my_left_nbr_lowhex(int to_divide_by, unsigned int nb, int len, char fill)
{
    char *digits = "0123456789abcdef";
    int out = 15;

    while (len > 1) {
        len--;
        my_putchar(fill);
    }
    while (to_divide_by >= 1) {
        out = nb / to_divide_by;
        nb = nb % to_divide_by;
        my_putchar(digits[out]);
        to_divide_by = to_divide_by / 16;
    }
}

void my_left_nbr_hexdcl(va_list list, int len, char fill)
{
    int digits = 0;
    int to_divide_by = 1;
    unsigned int nb = 0;

    nb = va_arg(list, unsigned int);
    if (nb == 0) {
        while (len > 1) {
            len--;
            my_putchar(fill);
        }
        my_putchar('0');
    }
    digits = calc_digits(nb, 16);
    len = len - digits;
    while (digits != 0) {
        to_divide_by = to_divide_by * 16;
        digits = digits - 1;
    }
    my_left_nbr_lowhex(to_divide_by, nb, len, fill);
}

void my_left_nbr_uphex(int to_divide_by, unsigned int nb, int len, char fill)
{
    char *digits = "0123456789ABCDEF";
    int out = 15;

    while (len > 1) {
        len--;
        my_putchar(fill);
    }
    while (to_divide_by >= 1) {
        out = nb / to_divide_by;
        nb = nb % to_divide_by;
        my_putchar(digits[out]);
        to_divide_by = to_divide_by / 16;
    }
}

void my_left_nbr_hexdcu(va_list list, int len, char fill)
{
    int digits = 0;
    int to_divide_by = 1;
    unsigned int nb = 0;

    nb = va_arg(list, unsigned int);
    if (nb == 0) {
        while (len > 1) {
            len--;
            my_putchar(fill);
        }
        my_putchar('0');
    }
    digits = calc_digits(nb, 16);
    len = len - digits;
    while (digits != 0) {
        to_divide_by = to_divide_by * 16;
        digits = digits - 1;
    }
    my_left_nbr_uphex(to_divide_by, nb, len, fill);
}
