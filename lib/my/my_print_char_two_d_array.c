/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_print_char_two_d_array.c
*/

#include "my.h"

int my_print_char_two_d_array(char **array)
{
    for (int x = 0; array[x]; x++) {
        my_putstr(array[x]);
        my_putchar('\n');
    }
    return (0);
}