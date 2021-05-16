/*
** EPITECH PROJECT, 2020
** my_sokoban
** File description:
** my_char_array_dup.c
*/

#include "my.h"

char **my_char_array_dup(char **array)
{
    char **new_array;
    int x;

    for (x = 0; array[x]; x++);
    new_array = malloc(sizeof(*new_array) * (x + 1));
    if (new_array == NULL)
        return (NULL);
    for (int i = 0; i < x; i++) {
        new_array[i] = my_strndup(array[i], my_strlen(array[i]));
        if (new_array[i] == NULL)
            return (NULL);
    }
    new_array[x] = NULL;
    return (new_array);
}