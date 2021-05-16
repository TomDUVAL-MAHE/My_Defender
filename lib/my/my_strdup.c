/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** A function that allocates memory and copies the string given as argument
** in it.
*/
#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *new_str;

    new_str = malloc((my_strlen(src) + 1) * sizeof(char));
    my_strcpy(new_str, src);
    return (new_str);
}