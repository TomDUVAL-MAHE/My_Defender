/*
** EPITECH PROJECT, 2020
** my_int_to_unsigned.c
** File description:
** Convert a int given as parameter to an unsigned int
*/

#include "my.h"

unsigned int my_int_to_unsigned(int i)
{
    unsigned int result;

    if (i < 0)
        result = i + 4294967295 + 1;
    else
        result = i;
    return (result);
}