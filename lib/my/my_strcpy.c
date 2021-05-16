/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** a function that copies a string into another. The destination string
** will already have enough memory to copy the source string
*/
#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; i <= my_strlen(src); i += 1) {
        dest[i] = src[i];
    }
    return (dest);
}
