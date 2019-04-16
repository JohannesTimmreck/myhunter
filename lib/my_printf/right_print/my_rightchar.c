/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** my_printf
*/

#include "../headerfile_printf.h"

void my_rightchar(va_list list, int nbr)
{
    char c = 0;

    c = va_arg(list, int);
    write(1, &c, 1);
    while (nbr > 1) {
        my_putchar(' ');
        nbr--;
    }
}
