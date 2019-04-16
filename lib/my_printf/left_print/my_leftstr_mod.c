/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** my_printf
*/

#include "../headerfile_printf.h"

int count_spec_dig(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] <= 32 || str[i] >= 127)
            count++;
        i++;
    }
    return (count);
}

void my_leftstr_mod(va_list list, int len, char fill)
{
    int i = 0;
    char *str = va_arg(list, char *);
    int nb = count_spec_dig(str);
    int save = 0;

    len = len - (nb * 4);
    fill = ' ';
    while (len >= my_strlen(str)) {
        my_putchar(fill);
        len--;
    }
    while (str[i] != '\0') {
        if (str[i] <= 32 || str[i] >= 127) {
            my_putchar('\\');
            save = str[i];
            my_left_nbr_oct_mod(save, 3, '0');
        } else {
            my_putchar(str[i]);
        }
        i++;
    }
}
