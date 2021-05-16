/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** This is a function which print ascii value in an octal base.
*/
#include "my.h"
#include <stdlib.h>

int my_putchar_unprintable(char c)
{
    int ascii_value = c;
    int i = 0;
    char *base = "01234567";
    char *result = my_calloc_char(sizeof(char), 5, '0');

    if (result == NULL)
        return (0);
    while (ascii_value > 0) {
        result[3 - i] = base[ascii_value % 8];
        ascii_value = ascii_value / 8;
        i++;
    }
    result[0] = '\\';
    result[4] = '\0';
    my_putstr(result);
    free(result);
    return (0);
}
