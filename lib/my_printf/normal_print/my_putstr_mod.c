/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** my_printf
*/

#include "../headerfile_printf.h"

void my_left_nbr_oct_mod(unsigned int nb, int len, char fill)
{
    int octs = 0;
    int to_divide_by = 1;

    if (nb == 0) {
        while (len > 1) {
            len--;
            my_putchar(fill);
        }
        my_putchar('0');
    }
    octs = calc_digits(nb, 8);
    len = len - octs;
    while (octs != 0) {
        to_divide_by = to_divide_by * 8;
        octs = octs - 1;
    }
    left_print_nbr_oct(to_divide_by, nb, len, fill);
}

void my_putstr_mod(va_list list)
{
    int i = 0;
    int save = 0;
    char *str;

    str = va_arg(list, char *);
    while (str[i] != '\0') {
        if (str[i] <= 32 || str[i] >= 127) {
            my_putchar('\\');
            save = str[i];
            my_left_nbr_oct_mod(save, 3, '0');
        } else {
            my_putchar(str[i]);
        }
        i = i + 1;
    }
}
