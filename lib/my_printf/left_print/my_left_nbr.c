/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** my_printf
*/

#include "../headerfile_printf.h"

void left_print_nbr(int to_divide_by, int nb, int len, char fill)
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
        to_divide_by = to_divide_by / 10;
        len--;
    }
}

int calc_to_divide_by(int nb)
{
    int tens = 0;
    int to_divide_by = 1;

    tens = right_calc_tens(nb);
    while (tens != 0) {
        to_divide_by = to_divide_by * 10;
        tens = tens - 1;
    }
    return (to_divide_by);
}

void my_left_nbr(va_list list, int len, char fill)
{
    int to_divide_by = 1;
    int nb = 0;

    nb = va_arg(list, int);
    if (nb == 0) {
        while (len > 1) {
            len--;
            my_putchar(fill);
        }
        my_putchar('0');
    }
    if (nb < 0) {
        my_putchar('-');
        len--;
        nb = nb * (-1);
    }
    to_divide_by = calc_to_divide_by(nb);
    left_print_nbr(to_divide_by, nb, len, fill);
}
