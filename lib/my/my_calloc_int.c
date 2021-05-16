/*
** EPITECH PROJECT, 2020
** my_calloc.c
** File description:
** My calloc
*/
#include <stdlib.h>
#include <stddef.h>
#include "my.h"

int *my_calloc_int(size_t nmemb, size_t size, int default_int)
{
    int *tab = malloc(nmemb * size);

    if (tab == NULL)
        return (NULL);
    my_memset_int(tab, default_int, size);
    return (tab);
}
