/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** my_printf
*/

#include "../headerfile_printf.h"

void my_rightstr(va_list list, int nbr)
{
    int i = 0;
    int j = 0;
    char *str;

    str = va_arg(list, char *);
    j = my_strlen(str);
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    while (j < nbr) {
        my_putchar(' ');
        j++;
    }
}
