/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** my_printf
*/

#include "../headerfile_printf.h"

void my_leftstr(va_list list, int len, char fill)
{
    int i = 0;
    char *str;

    fill = ' ';
    str = va_arg(list, char *);
    while (my_strlen(str) < len) {
        my_putchar(fill);
        len--;
    }
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}
