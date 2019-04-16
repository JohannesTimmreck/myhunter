/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** my_printf
*/

#include "../headerfile_printf.h"

void my_rightstr_mod(va_list list, int len)
{
    int i = 0;
    char *str = va_arg(list, char *);
    int save = 0;

    while (str[i] != '\0') {
        if (str[i] <= 32 || str[i] >= 127) {
            my_putchar('\\');
            save = str[i];
            my_left_nbr_oct_mod(save, 3, '0');
            len = len - 4;
        } else {
            my_putchar(str[i]);
            len--;
        }
        i++;
    }
    while (len > 0) {
        len--;
        my_putchar(' ');
    }
}
