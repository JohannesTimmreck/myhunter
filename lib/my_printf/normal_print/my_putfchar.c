/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** my_printf
*/

#include "../headerfile_printf.h"

void my_putfchar(va_list list)
{
    char c = 0;

    c = va_arg(list, int);
    write(1, &c, 1);
}

void my_putperc(va_list list)
{
    char c = '%';

    (void) list;
    write(1, &c, 1);
}
