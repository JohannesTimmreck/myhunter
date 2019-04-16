/*
** EPITECH PROJECT, 2018
** mygetnbr
** File description:
** getnbr
*/

int is_fneg(char const *str)
{
    int i;
    int counter;

    i = 0;
    counter = 0;
    while (str[i] > '9' || str[i] < '0')
    {
        if (str[i] == '-')
            counter = counter + 1;
        i = i + 1;
    }
    if (counter % 2 != 0)
        return (1);
    else
        return (0);
}

int is_fnum(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else if (c == '+' || c == '-')
        return (2);
    else
        return (0);
}

int my_getfnbr(char const *str, int *count)
{
    int i = *count;
    int nbr = 0;

    if (!str)
        return (0);
    while (is_fnum(str[i]) == 2)
        i = i + 1;
    while (is_fnum(str[i]) == 1)
    {
        nbr = ((nbr * 10) + (str[i] - 48));
        i = i + 1;
    }
    if (is_fneg(str) == 1)
        nbr = -nbr;
    *count = i;
    return (nbr);
}
