/*
** EPITECH PROJECT, 2018
** my_putnbr_oct
** File description:
** my_printf
*/

#include "../headerfile_printf.h"

void my_print_nbr_bin(int to_divide_by, unsigned int nb)
{
    int out = 1;

    while (to_divide_by >= 1) {
        out = nb / to_divide_by;
        nb = nb % to_divide_by;
        my_putchar(out + '0');
        to_divide_by = to_divide_by / 2;
    }
}

void my_put_nbr_bin(va_list list)
{
    int digits = 0;
    int to_divide_by = 1;
    unsigned int nb = 0;

    nb = va_arg(list, unsigned int);
    if (nb == 0) {
        my_putchar('0');
    }
    digits = calc_digits(nb, 2);
    while (digits != 0) {
        to_divide_by = to_divide_by * 2;
        digits = digits - 1;
    }
    my_print_nbr_bin(to_divide_by, nb);
}
