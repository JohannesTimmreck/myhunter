/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** my_printf
*/

#include "../headerfile_printf.h"

void my_putstr(va_list list)
{
    int i = 0;
    char *str;

    str = va_arg(list, char *);
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}
