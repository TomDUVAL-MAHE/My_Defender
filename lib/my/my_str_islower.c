/*
** EPITECH PROJECT, 2020
** my_str_islower
** File description:
** a function that returns 1 if the string passed as parameter only
** contains lowercase alphabetical characters and 0 otherwise.
*/
#include "my.h"

int my_str_islower(char const *str)
{
    int i;

    for (i = 0; i < my_strlen(str); i += 1) {
        if (str[i] > 'z' || str[i] < 'a')
            return (0);
    }
    return (1);
}
