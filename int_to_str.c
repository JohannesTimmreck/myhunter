/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** int to str
*/

int calc_to_divide_by_str(int temp)
{
    int tens = 0;
    int to_divide_by = 1;

    while (temp != 0) {
        temp = temp / 10;
        tens = tens + 1;
    }
    tens = tens - 1;
    while (tens != 0) {
        to_divide_by = to_divide_by * 10;
        tens = tens - 1;
    }
    return (to_divide_by);
}

char *put_int_str(char *str, int to_divide_by, int nb, int counter)
{
        int out = 1;

        while (to_divide_by >= 1) {
            out = nb / to_divide_by;
            nb = nb % to_divide_by;
            str[counter] = out + '0';
            counter++;
            to_divide_by = to_divide_by / 10;
        }
        str[counter] = '\0';
        return (str);
}

char *int_to_str(int nb, char *str)
{
    int to_divide_by = 1;
    int counter = 0;

    if (nb == 0) {
        str[counter] = '0';
        str[counter + 1] = '\0';
        return (str);
    }
    if (nb < 0) {
        str[counter] = '-';
        counter++;
        nb = nb * (- 1);
    }
    to_divide_by = calc_to_divide_by_str(nb);
    str = put_int_str(str, to_divide_by, nb, counter);
    return (str);
}
