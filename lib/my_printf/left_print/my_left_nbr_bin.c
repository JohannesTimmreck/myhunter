/*
** EPITECH PROJECT, 2018
** my_putnbr_oct
** File description:
** my_printf
*/

#include "../headerfile_printf.h"

void left_print_nbr_bin(int to_divide_by, unsigned int nb, int len, char fill)
{
    int out = 1;

    while (len > 1) {
        len--;
        my_putchar(fill);
    }
    while (to_divide_by >= 1) {
        out = nb / to_divide_by;
        nb = nb % to_divide_by;
        my_putchar(out + '0');
        to_divide_by = to_divide_by / 2;
    }
}

void my_left_nbr_bin(va_list list, int len, char fill)
{
    int octs = 0;
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
    octs = calc_digits(nb, 2);
    len = len - octs;
    while (octs != 0) {
        to_divide_by = to_divide_by * 2;
        octs = octs - 1;
    }
    left_print_nbr_bin(to_divide_by, nb, len, fill);
}
