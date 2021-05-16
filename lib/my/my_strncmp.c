/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** Reproduce the behavior of the strcmp function.
*/
#include "my.h"

int my_strncmp(char const *str, char const *cmp, int n)
{
    int i = 0;

    while (i < my_strlen(str) && i < my_strlen(cmp) && i < n) {
        if (str[i] == cmp[i]) {
            i += 1;
        }
        else
            return (str[i] - cmp[i]);
    }
    return (0);
}
