/*
** EPITECH PROJECT, 2020
** my_show_word_array
** File description:
** a function that displays the content of an array of words.
*/
#include "my.h"

int my_show_word_array(char * const *tab)
{
    int i;

    for (i = 0; tab[i]; i += 1) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}
