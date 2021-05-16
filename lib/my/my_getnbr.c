/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** A function that return a int given as a character
*/
#include "my.h"

int my_getnbr(char const *str)
{
    int i;
    int neg = 0;
    int complete_nbr = 0;

    for (i = 0; (str[i] > '9' || str[i] < '0') && i < my_strlen(str); i += 1) {
        if (str[i] == '-')
            neg += 1;
    }
    while ((str[i] <= '9' && str[i] >= '0') && i < my_strlen(str)) {
        complete_nbr = complete_nbr * 10 + (str[i]-'0');
        i += 1;
    }
    if (neg % 2 == 0)
        return (complete_nbr);
    else
        return (complete_nbr * -1);
}
