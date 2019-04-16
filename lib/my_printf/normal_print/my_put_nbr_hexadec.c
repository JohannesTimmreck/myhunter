/*
** EPITECH PROJECT, 2018
** put hexadec nbr
** File description:
** my_printf
*/


#include "../headerfile_printf.h"

void my_print_nbr_lowhex(int to_divide_by, unsigned int nb)
{
    char *digits = "0123456789abcdef";
    int out = 15;

    while (to_divide_by >= 1) {
        out = nb / to_divide_by;
        nb = nb % to_divide_by;
        my_putchar(digits[out]);
        to_divide_by = to_divide_by / 16;
    }
}

void my_put_nbr_hexdcl(va_list list)
{
    int digits = 0;
    int to_divide_by = 1;
    unsigned int nb = 0;

    nb = va_arg(list, unsigned int);
    if (nb == 0) {
        my_putchar('0');
    }
    digits = calc_digits(nb, 16);
    while (digits != 0) {
        to_divide_by = to_divide_by * 16;
        digits = digits - 1;
    }
    my_print_nbr_lowhex(to_divide_by, nb);

}

void my_print_nbr_uphex(int to_divide_by, unsigned int nb)
{
    char *digits = "0123456789ABCDEF";
    int out = 15;

    while (to_divide_by >= 1) {
        out = nb / to_divide_by;
        nb = nb % to_divide_by;
        my_putchar(digits[out]);
        to_divide_by = to_divide_by / 16;
    }
}

void my_put_nbr_hexdcu(va_list list)
{
    int digits = 0;
    int to_divide_by = 1;
    unsigned int nb = 0;

    nb = va_arg(list, unsigned int);
    if (nb == 0) {
        my_putchar('0');
    }
    digits = calc_digits(nb, 16);
    while (digits != 0) {
        to_divide_by = to_divide_by * 16;
        digits = digits - 1;
    }
    my_print_nbr_uphex(to_divide_by, nb);

}
