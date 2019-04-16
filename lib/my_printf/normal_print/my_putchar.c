/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** my_printf
*/

#include "../headerfile_printf.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
