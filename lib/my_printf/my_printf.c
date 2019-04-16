/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

#include "headerfile_printf.h"

void print_right(char src, va_list list, int nbr)
{
    char flag[10] = "scdiouxXbS";
    int i = 0;
    right_ptr fct_put[] = {&my_rightstr, &my_rightchar, &my_right_nbr,
                            &my_right_nbr, &my_right_nbr_oct, &my_right_nbr_dec,
                            &my_right_nbr_hexdcl, &my_right_nbr_hexdcu,
                            &my_right_nbr_bin, &my_rightstr_mod};

    while (i <= 9) {
        if (flag[i] == src) {
            fct_put[i](list, nbr);
            return;
        }
        i++;
    }
}

void print_left(char src, va_list list, int nbr, char fill)
{
    char flag[10] = "scdiouxXbS";
    int i = 0;
    left_ptr fct_put[] = {&my_leftstr, &my_leftchar, &my_left_nbr, &my_left_nbr,
                            &my_left_nbr_oct, &my_left_nbr_dec,
                            &my_left_nbr_hexdcl, &my_left_nbr_hexdcu,
                            &my_left_nbr_bin, &my_leftstr_mod};

    while (i <= 9) {
        if (flag[i] == src) {
            fct_put[i](list, nbr, fill);
            return;
        }
        i++;
    }
}

void flag_print(char const *src, va_list list, int *count)
{
    int zero = 0;
    int nbr = 0;

    if (src[*count] == '0') {
        zero++;
        *count = *count + 1;
    }
    nbr = my_getfnbr(src, count);
    if (nbr < 0) {
        nbr = nbr * (-1);
        print_right(src[*count], list, nbr);
    } else if (zero == 1) {
        print_left(src[*count], list, nbr, '0');
    } else {
        print_left(src[*count], list, nbr, ' ');
    }
}

void organize_print(char const *src, va_list list, int *count)
{
    char flag[11] = "scdiouxX%bS";
    int i = 0;
    fct_ptr fct_put[] = {&my_putstr, &my_putfchar, &my_put_nbr, &my_put_nbr,
                            &my_put_nbr_oct, &my_put_nbr_dec,
                            &my_put_nbr_hexdcl, &my_put_nbr_hexdcu,
                            &my_putperc, &my_put_nbr_bin, &my_putstr_mod};

    while (i <= 10) {
        if (flag[i] == src[*count]) {
            fct_put[i](list);
            return;
        }
        i++;
    }
    flag_print(src, list, count);
}

int my_printf(char const *src, ...)
{
    va_list list;
    int count = 0;
    int count_all = 0;

    va_start(list, src);
    while (src[count] != '\0') {
        if (src[count] == '%') {
            count++;
            count_all++;
            organize_print(src, list, &count);
        } else {
            my_putchar(src[count]);
        }
        count++;
        count_all++;
    }
    va_end(list);
    return (count_all);
}
