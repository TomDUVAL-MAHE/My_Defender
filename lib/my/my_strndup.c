/*
** EPITECH PROJECT, 2020
** minishell_1
** File description:
** my_strndup.c
*/

#include <stdlib.h>
#include "my.h"

char *my_strndup(char const *src, int n)
{
    char *new_str;

    new_str = my_calloc_char(sizeof(char), n + 1, '\0');
    my_strncpy(new_str, src, n);
    return (new_str);
}