/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** my_printf
*/

#include "../headerfile_printf.h"

void my_leftchar(va_list list, int len, char fill)
{
    char c = 0;

    fill = ' ';
    while (len > 1) {
        len--;
        my_putchar(fill);
    }
    c = va_arg(list, int);
    write(1, &c, 1);
}
