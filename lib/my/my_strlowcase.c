/*
** EPITECH PROJECT, 2020
** my_strlowcase
** File description:
** A function that puts every letter of every word in it in lowercase.
*/
#include "my.h"

char *my_strlowcase(char *str)
{
    int i;

    for (i = 0; i < my_strlen(str); i += 1) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    return (str);
}
