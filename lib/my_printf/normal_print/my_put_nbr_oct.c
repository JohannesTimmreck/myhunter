/*
** EPITECH PROJECT, 2018
** my_putnbr_oct
** File description:
** my_printf
*/

#include "../headerfile_printf.h"

int calc_digits(unsigned int temp, int base)
{
    int digits = 0;

    while (temp != 0) {
        temp = temp / base;
        digits = digits + 1;
    }
    digits--;
    return (digits);
}

void my_print_nbr_oct(int to_divide_by, unsigned int nb)
{
    int out = 1;

    while (to_divide_by >= 1) {
        out = nb / to_divide_by;
        nb = nb % to_divide_by;
        my_putchar(out + '0');
        to_divide_by = to_divide_by / 8;
    }
}

void my_put_nbr_oct(va_list list)
{
    int octs = 0;
    int to_divide_by = 1;
    unsigned int nb = 0;

    nb = va_arg(list, unsigned int);
    if (nb == 0) {
        my_putchar('0');
    }
    octs = calc_digits(nb, 8);
    while (octs != 0) {
        to_divide_by = to_divide_by * 8;
        octs = octs - 1;
    }
    my_print_nbr_oct(to_divide_by, nb);

}
