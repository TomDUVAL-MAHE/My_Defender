/*
** EPITECH PROJECT, 2020
** my_putnbr_base.c
** File description:
** Display a decimal integer into an other base given as parameter
*/

#include "my.h"
#include <stdlib.h>

int my_putnbr_base(int nbr, char const *base)
{
    unsigned int new = my_int_to_unsigned(nbr);
    int i = 0;
    int len_base = my_strlen(base);
    char *result = my_calloc_char(sizeof(char), 33, '\0');

    if (result == NULL)
        return (84);
    while (new > 0) {
        my_strncat(result, base + (new % len_base), 1);
        new /= len_base;
        i++;
    }
    my_putstr(my_revstr(result));
    free(result);
    return (0);
}
