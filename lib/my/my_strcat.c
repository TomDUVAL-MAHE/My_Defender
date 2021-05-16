/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** a function that concatenates two strings
*/
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i;
    int length = my_strlen(dest);

    for (i = 0; src[i] != '\0'; i += 1)
        dest[length + i] = src[i];
    dest[length + i] = '\0';
    return (dest);
}
