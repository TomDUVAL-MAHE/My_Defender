/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
**  a function that concatenates n characters of the src string to the end
** of the dest string.
*/
#include "my.h"

char *my_strncat(char *dest, char const *src, int n)
{
    if (n < 0)
        return (my_strcat(dest, src));
    for (int i = 0; i < n && src[i] != '\0'; i += 1) {
        dest[my_strlen(dest)] = src[i];
    }
    dest[my_strlen(dest)] = '\0';
    return (dest);
}
