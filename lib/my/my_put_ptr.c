/*
** EPITECH PROJECT, 2020
** my_putnbr_base.c
** File description:
** Display a decimal integer into an other base given as parameter
*/

#include "my.h"
#include <stdlib.h>

int my_put_ptr(unsigned long ptr)
{
    int i = 0;
    char *base = "0123456789abcdef";
    char *result = my_calloc_char(sizeof(char), 33, '\0');

    if (result == NULL)
        return (84);
    while (ptr > 0) {
        my_strncat(result, base + (ptr % 16), 1);
        ptr /= 16;
        i++;
    }
    my_putstr("0x");
    my_putstr(my_revstr(result));
    free(result);
    return (0);
}
