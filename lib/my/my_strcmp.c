/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** Reproduce the behavior of the strcmp function.
*/
#include "my.h"

int my_strcmp(char const *str, char const *cmp)
{
    int i = 0;

    while (str[i] == cmp[i] && i < my_strlen(str) && i < my_strlen(cmp)) {
        i += 1;
    }
    return (str[i] - cmp[i]);
}
