/*
** EPITECH PROJECT, 2020
** my_memset
** File description:
** My memset function
*/
#include <stdlib.h>
#include "my.h"

int *my_memset_int(int *tab, int c, size_t n)
{
    for (int i = 0; i < n; i++) {
        tab[i] = c;
    }
    return (tab);
}
