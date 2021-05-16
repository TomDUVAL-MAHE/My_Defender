/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** a function that copies n characters from a string into another.
*/
#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i < n; i += 1) {
        if (i > my_strlen(src) || i == n) {
            dest[i] = '\0';
            return (dest);
        }
        else
            dest[i] = src[i];
    }
    return (dest);
}
