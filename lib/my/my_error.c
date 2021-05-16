/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_error.c
*/

#include "my.h"

int my_error(char *message, int return_value)
{
    my_putstr_error(message);
    return (return_value);
}