/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** my_putstr_error.c
*/

#include "my.h"

void my_putstr_error(char *message)
{
    write(2, message, my_strlen(message));
}