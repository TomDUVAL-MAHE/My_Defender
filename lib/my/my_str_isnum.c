/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** a function that returns 1 if the string passed as parameter only
** contains digits and 0 otherwise.
*/
#include "my.h"

bool my_str_isnum(char const *str)
{
    int i;

    for (i = 0; i < my_strlen(str); i += 1) {
        if (str[i] < '0' || str[i] > '9')
            return (false);
    }
    return (true);
}
