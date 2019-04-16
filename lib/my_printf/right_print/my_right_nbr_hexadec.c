/*
** EPITECH PROJECT, 2018
** put hexadec nbr
** File description:
** my_printf
*/


#include "../headerfile_printf.h"

void my_right_nbr_lowhex(int to_divide_by, unsigned int nb, int len)
{
    char *digits = "0123456789abcdef";
    int out = 15;

    while (to_divide_by >= 1) {
        out = nb / to_divide_by;
        nb = nb % to_divide_by;
        my_putchar(digits[out]);
        to_divide_by = to_divide_by / 16;
        len--;
    }
    while (len > 0) {
        len--;
        my_putchar(' ');
    }
}

void my_right_nbr_hexdcl(va_list list, int len)
{
    int digits = 0;
    int to_divide_by = 1;
    unsigned int nb = 0;

    nb = va_arg(list, unsigned int);
    if (nb == 0) {
        my_putchar('0');
        len--;
    }
    digits = calc_digits(nb, 16);
    while (digits != 0) {
        to_divide_by = to_divide_by * 16;
        digits = digits - 1;
    }
    my_right_nbr_lowhex(to_divide_by, nb, len);
}

void my_right_nbr_uphex(int to_divide_by, unsigned int nb, int len)
{
    char *digits = "0123456789ABCDEF";
    int out = 15;

    while (to_divide_by >= 1) {
        out = nb / to_divide_by;
        nb = nb % to_divide_by;
        my_putchar(digits[out]);
        to_divide_by = to_divide_by / 16;
        len--;
    }
    while (len > 0) {
        len--;
        my_putchar(' ');
    }
}

void my_right_nbr_hexdcu(va_list list, int len)
{
    int digits = 0;
    int to_divide_by = 1;
    unsigned int nb = 0;

    nb = va_arg(list, unsigned int);
    if (nb == 0) {
        my_putchar('0');
        len--;
    }
    digits = calc_digits(nb, 16);
    while (digits != 0) {
        to_divide_by = to_divide_by * 16;
        digits = digits - 1;
    }
    my_right_nbr_uphex(to_divide_by, nb, len);

}
