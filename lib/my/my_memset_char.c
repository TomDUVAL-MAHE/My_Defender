/*
** EPITECH PROJECT, 2020
** my_memset
** File description:
** My memset function
*/
#include <stdlib.h>
#include <stddef.h>
#include "my.h"

char *my_memset_char(char *s, char c, size_t n)
{
    for (int i = 0; i < n; i++) {
        s[i] = c;
    }
    return (s);
}
