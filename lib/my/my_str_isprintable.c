/*
** EPITECH PROJECT, 2020
** my_str_isprintable
** File description:
** a function that returns 1 if the string passed as parameter only
** contains printable characters and 0 otherwise.
*/
#include "my.h"

int my_str_isprintable(char const *str)
{
    int i;

    for (i = 0; i < my_strlen(str); i++) {
        if (str[i] == 127 || str[i] < 32)
            return (0);
    }
    return (1);
}
