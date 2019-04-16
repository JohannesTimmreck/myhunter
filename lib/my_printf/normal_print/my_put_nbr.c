/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** my_printf
*/

#include "../headerfile_printf.h"

int calc_tens(int temp)
{
    int tens = 0;

    while (temp != 0) {
        temp = temp / 10;
        tens = tens + 1;
    }
    tens = tens - 1;
    return (tens);
}

void my_print_nbr(int to_divide_by, int nb)
{
    int out = 1;

    while (to_divide_by >= 1) {
        out = nb / to_divide_by;
        nb = nb % to_divide_by;
        my_putchar(out + '0');
        to_divide_by = to_divide_by / 10;
    }
}

void my_put_nbr(va_list list)
{
    int tens = 0;
    int to_divide_by = 1;
    int nb = 0;

    nb = va_arg(list, int);
    if (nb == 0) {
        my_putchar('0');
        return;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    tens = calc_tens(nb);
    while (tens != 0) {
        to_divide_by = to_divide_by * 10;
        tens = tens - 1;
    }
    my_print_nbr(to_divide_by, nb);
}
