/*
** EPITECH PROJECT, 2020
** my_str_isupper
** File description:
** a function that returns 1 if the string passed as parameter only
** contains uppercase alphabetical characters and 0 otherwise.
*/
#include "my.h"

int my_str_isupper(char const *str)
{
    int i;

    for (i = 0; i < my_strlen(str); i += 1) {
        if (str[i] > 'Z' || str[i] < 'A')
            return (0);
    }
    return (1);
}
