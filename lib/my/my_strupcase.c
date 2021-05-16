/*
** EPITECH PROJECT, 2020
** my_strupcase
** File description:
** A function that puts every letter of every word in it in uppercase.
*/
#include "my.h"

char *my_strupcase(char *str)
{
    int i;

    for (i = 0; i < my_strlen(str); i += 1) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
    return (str);
}
