/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** a function that returns 1 if the string passed as parameter only
** contains alphabetical characters and 0 if the string contains
** another type of character.
*/
#include "my.h"

int my_str_isalpha(char const *str)
{
    int i;

    for (i = 0; i < my_strlen(str); i++) {
        if (str[i] > 'z' || str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a'))
            return (0);
    }
    return (1);
}
