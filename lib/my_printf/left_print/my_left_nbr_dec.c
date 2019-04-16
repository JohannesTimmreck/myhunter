/*
** EPITECH PROJECT, 2018
** my_putnbr_dec
** File description:
** my_printf
*/

#include "../headerfile_printf.h"

void left_unbr(int to_divide_by, unsigned int nb, int len, char fill)
{
    int out = 1;

    while (len > 2) {
        len--;
        my_putchar(fill);
    }
    while (to_divide_by >= 1) {
        out = nb / to_divide_by;
        nb = nb % to_divide_by;
        my_putchar(out + '0');
        to_divide_by = to_divide_by / 10;
    }
}

void my_left_nbr_dec(va_list list, int len, char fill)
{
    int tens = 0;
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
    tens = calc_tens(nb);
    while (tens != 0) {
        to_divide_by = to_divide_by * 10;
        tens = tens - 1;
    }
    left_unbr(to_divide_by, nb, len, fill);
}
