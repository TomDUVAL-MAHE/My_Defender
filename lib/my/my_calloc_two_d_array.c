/*
** EPITECH PROJECT, 2020
** my_sokoban
** File description:
** my_calloc_two_d_array.c
*/

#include "my.h"

char **my_calloc_two_d_array(int nb_rows, int nb_cols, char initial_char)
{
    char **array = malloc(sizeof(*array) * (nb_rows + 1));

    if (array == NULL) {
        my_putstr_error("An error has occurred with the memory\n");
        return (NULL);
    }
    for (int i = 0; i < nb_rows; i++) {
        array[i] = my_calloc_char(sizeof(char), nb_cols + 1, initial_char);
        if (array[i] == NULL) {
            my_putstr_error("An error has occurred with the memory\n");
            return (NULL);
        }
    }
    array[nb_rows] = NULL;
    return (array);
}